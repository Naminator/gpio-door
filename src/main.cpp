#include "stdafx.h"
#include "GarageDoor/Console.h"
#include "GarageDoor/GPIO/Manager.h"
#include "GarageDoor/Filesystem.h"
#include "nlohmann/json/json.hpp"

unsigned int hardwareConcurrency = 0;
bool serverRunning = true;

// Convenience
using json = nlohmann::json;

int main(int, char**)
{
    GarageDoor::Console::SetTitle(TEXT("Garage Door Opener Console"));
    GarageDoor::Console::WriteLine(TEXT("GarageDoor Initializing..."));

    hardwareConcurrency = std::thread::hardware_concurrency();

    std::stringstream ss;
    ss << "Hardware Concurrency: " << hardwareConcurrency;

    GarageDoor::Console::WriteLine(ss.str());
    GarageDoor::Console::WriteLine(TEXT("Reading GPIO pins..."));

    GarageDoor::GPIO::Manager * gpioManager = new GarageDoor::GPIO::Manager;
    gpioManager->LoadPins();

    GarageDoor::Console::WriteLine(TEXT("Done reading GPIO pins."));
    std::cout << gpioManager->CountPins() << " pins loaded." << std::endl;

    std::cout << "Loading JSON settings" << std::endl;
    tstring jsonSettings = GarageDoor::Filesystem::ReadFile("./settings.json");

    if (jsonSettings == "error")
    {
        std::cerr << "Error reading the settings.json config." << std::endl;
        exit(EXIT_FAILURE);
    }

    json j = json::parse(jsonSettings);
    std::cout << j["pin_mapping"]["tsochev_door"] << std::endl;

    if (gpioManager->CountPins() == 0)
    {
        exit(EXIT_FAILURE);
    }

    gpioManager->UnloadPins();
    delete gpioManager;

    exit(EXIT_SUCCESS);

    // Prepare syslog for entries
    // This should be excluded under windows, but fuck windows for now :D
    setlogmask(LOG_UPTO(LOG_NOTICE));
    openlog(DAEMON_NAME, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    syslog(LOG_INFO, "Starting Garage Door Daemon...");

    pid_t pid,sid;

    // Fork the process
    pid = fork();
    if (pid < 0) { exit(EXIT_FAILURE); }

    // We got a good pid, Close the parent process
    if (pid > 0) { exit(EXIT_SUCCESS); }

    umask(0);
    sid = setsid();
    if (sid < 0) { exit(EXIT_FAILURE); }

    if ( (chdir("/")) < 0 ) { exit(EXIT_FAILURE); }

    //Close Standard File Descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Begin the Bluetooth listen loop
    while(serverRunning)
    {
        // do something
        sleep(10);
        serverRunning = false;
    }

    // Close the log
    closelog();
}
