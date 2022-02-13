#include "CliUserInterface.hpp"
#include "CommandFactory.hpp"
#include "CommandInterpreter.hpp"
#include "CommandIssuedObserver.hpp"

using std::make_unique;

int main()
{
    auto cli = CliUserInterface(std::cin, std::cout);
    
    CommandInterpreter ci(cli);

    RegisterCoreCommands(cli);

    cli.attach(UserInterface::commandEntered(), make_unique<CommandIssuedObserver>());

    // attach cli to state changed entered event in mp3player

    cli.execute();
}