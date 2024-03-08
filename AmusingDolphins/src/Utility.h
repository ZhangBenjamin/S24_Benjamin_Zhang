#pragma once

#define START_GAME(className) \
int main()\
{\
	className _game;\
	_game.Run();\
	return 0;\
}


#ifdef AMUSING_DOLPHINS_MS_COMPILER
	#ifdef AMUSING_DOLPHINS_LIB
		#define AMUSING_DOLPHINS_API __declspec(dllexport)
	#else
		#define AMUSING_DOLPHINS_API __declspec(dllimport)
	#endif
#else 
	#define AMUSING_DOLPHINS_API
#endif


#if AMUSING_DOLPHINS_DEBUG == 2
	#define AMUSING_DOLPHINS_ERROR(x) std::cout<<x<<std::endl;
	#define AMUSING_DOLPHINS_LOG(x) std::cout<<x<<std::endl;

#elif AMUSING_DOLPHINS_DEBUG == 1
	#define AMUSING_DOLPHINS_ERROR(x) std::cout<<x<<std::endl;
	#define AMUSING_DOLPHINS_LOG(x) 

#else
	#define AMUSING_DOLPHINS_ERROR(x) 
	#define AMUSING_DOLPHINS_LOG(x) 

#endif