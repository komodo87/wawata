#define WAW_PROFILE_CORE 0x32001
#define WAW_PROFILE_COMPAT 0x32002

namespace wawata
{
	bool init(int context_version_major = 4, int context_version_minor = 6, int profile = WAW_PROFILE_CORE);
	void terminate();
	double get_time(); 
}
