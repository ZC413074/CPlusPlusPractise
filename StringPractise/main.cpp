#include"test.h"
#include<chrono>
#include<ctime>
#include<windows.h>
#include<vector>

int main()
{
	std::cout << "\string_correct_completion: " << "\n";
	std::vector<std::string> sources0 = { "30039", "HX0D30039", "HXDD3003", "HHXD30039BB", "HD30039", "XH30039", "XD30039","D30039" };
	std::vector<std::string> sources1 = { "HXD300039", "HXD3C003", "HXD3C0039B", "HD3C0039", "HX3C0039", "XD3C0039","D3C0039","3C0039" };
	std::vector<std::string> sources2 = { "HXD30A0039", "HXD3CA003", "HXD3CA0039B", "HD3CA0039", "HX30A0039", "XD3CA0039","D3CA0039" };

	std::vector<std::string> sources4 = { "SS30039", "SS3E0039",  "SS3D0039","SS3D0039","S30039" };
	std::vector<std::string> sources6 = { "CH1A0039", "RH1E0039", "CR1A0039","R1A0039", "3008A0039", "CRH400AF0039","CRH380AF0039" };
	std::vector<std::string> output_string;
	string_correct_completion(sources4, output_string);
	return 0;
}