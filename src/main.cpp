#include <shSys.hpp>
#include <shInit.hpp>

#define NONE sh::flags::argCase::none
#define DEMO sh::flags::argCase::demo
#define WINDOWED sh::flags::argCase::windowed
#define NOVID sh::flags::argCase::novid
#define NOSOUND sh::flags::argCase::noSound
#define NOSAVE sh::flags::argCase::noSave
#define HELP sh::flags::argCase::help

sh::flags::argCase hashFunc(const char* arg) 
{
	std::string m_arg = arg;
	char dash = m_arg[0];
	if(dash != '-') return NONE;
	m_arg.erase(0, 1);
	if(m_arg == "demo") return DEMO;
	if(m_arg == "windowed") return WINDOWED;
	if(m_arg == "novid") return NOVID;
	if(m_arg == "nosound") return NOSOUND;
	if(m_arg == "nosave") return NOSAVE;
	if(m_arg == "help") return HELP;
	return NONE;
}

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			switch(hashFunc(argv[i]))
			{
			case DEMO:
			{
				sh::flags::demo = true;
			} break;
			case WINDOWED:
			{
				sh::flags::windowed = true;
			} break;
			case NOVID:
			{
				sh::flags::noVid = true;
			}break;
			case NOSOUND:
			{
				sh::flags::noSound = true;
			}break;
			case NOSAVE:
			{
				sh::flags::noSave = true;
			}break;
			case HELP:
			{
				std::cout << "-help: Display this list\n"
				"-demo: Run in demo mode\n" 
				"-windowed: Run in windowed mode\n"
				"-novid: Skip startup animations.\n"
				"-nosound: Disable all audio.\n"
				"-nosave: Disable saving.\n"
				<< std::endl;
				return 0;
			}break;
			default: break;
			}
			
		}
	}
	
    try { startApp(); }
	catch (sh::sh_Panic)
	{
		std::cin.get();
		return EXIT_FAILURE;
	}
	return 0;
}
