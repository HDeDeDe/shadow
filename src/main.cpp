#include <shSys.hpp>
#include <shInit.hpp>

sh::flags::argCase hashFunc(const char* arg) 
{
	std::string m_arg = arg;
	char dash = m_arg[0];
	if(dash != '-') return sh::flags::argCase::none;
	m_arg.erase(0, 1);
	if(m_arg == "demo") return sh::flags::argCase::demo;
	if(m_arg == "windowed") return sh::flags::argCase::windowed;
	if(m_arg == "novid") return sh::flags::argCase::novid;
	if(m_arg == "nosound") return sh::flags::argCase::noSound;
	if(m_arg == "help") return sh::flags::argCase::help;
	return sh::flags::argCase::none;
}

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			switch(hashFunc(argv[i]))
			{
			case sh::flags::argCase::demo:
			{
				sh::flags::demo = true;
			} break;
			case sh::flags::argCase::windowed:
			{
				sh::flags::windowed = true;
			} break;
			case sh::flags::argCase::novid:
			{
				sh::flags::noVid = true;
			}break;
			case sh::flags::argCase::noSound:
			{
				sh::flags::noSound = true;
			}break;
			case sh::flags::argCase::help:
			{
				std::cout << "-demo: Run in demo mode\n" 
				"-windowed: Run in windowed mode\n"
				"-novid: Skip startup animations.\n"
				"-nosound: Disable all audio.\n"
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
