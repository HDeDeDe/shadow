#include <shSys.hpp>
#include <shInit.hpp>

int main()
{
    try { startApp(); }
	catch (sh::sh_Panic)
	{
		std::cin.get();
		return EXIT_FAILURE;
	}
	return 0;
}
