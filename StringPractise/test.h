#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<map>
#include<memory>

enum TrianNumberType
{
	Nothing,
	HXD,
	CRH,
	SS
};

int judge_all_nums(const std::string& str)
{
	return std::atoi(str.c_str());
}

std::string remove_tail(const std::string& str)
{
	int i = 0;
	for (i = int(str.length()) -1; i >-1e-6; i--)
	{
		if (str[i]<'A') break;
	}
	return str.substr(0, i + 1);
}
 
std::string remove_duplicates(const std::string& str)
{
	std::string new_str;
	for (const char& ch : str) 
	{
		if (!new_str.empty() && ch != 'S' && ch>'A' && new_str.back() == ch)
		{
			continue;
		}
		else 
		{
			new_str.push_back(ch);
		}
	}
	return new_str;
}

std::string process_ss(const std::string& str)
{
	int nums_len = 0;
	std::string out_string(" ");
	std::string::size_type pos = std::string::npos;

	auto print_string = [](const std::string& str, const int& pos, const int& nums_len)
	{
		std::string out_string(" ");
		if (str[pos + 1]<'8' && str[pos + 1] > '2' && nums_len > 3)
		{
			switch (nums_len)
			{
			case 4:
				out_string = std::string("SS") + str.substr(pos + 1, str.length());
				break;
			case 5:
				out_string = std::string("SS") + str.substr(pos + 1, str.length());
				break;
			case 6:
				if (str[pos + 2] == '0') out_string = std::string("SS") + str[pos + 1] + std::string("C") + str.substr(pos + 3, str.length());
				else out_string = std::string("SS") + str.substr(pos + 1, str.length());
				break;

			default:
				if (str[pos + 2] == '0') out_string = std::string("SS") + str[pos + 1] + std::string("C") + str.substr(pos + 3, pos + 3 + 6);
				else out_string = std::string("SS") + str.substr(pos + 1, pos + 3 + 6);
				break;
			}
		}
		else if(str[pos + 1]>'A'&& str[pos + 1] < 'F')
		{
			out_string = std::string("SS3") + str.substr(pos + 1, str.length());
		}
		return out_string;
	};

	if ((pos = str.find_last_of('S')) != std::string::npos)
	{
		nums_len = int(str.length()) - int(pos) - 1;
		out_string = print_string(str, pos, nums_len);
	}

	return out_string;
}

std::string process_crh(const std::string& str)
{
	int nums_len = 0;
	std::string out_string(" ");
	std::string::size_type pos = std::string::npos;

	auto print_string = [](const std::string& str, const int& pos, const int& nums_len)
	{
		std::string out_string(" ");
		if (str[pos + 1]<'7' && str[pos + 1] > '0' && nums_len > 4)
		{
			out_string = std::string("CRH") + str.substr(pos + 1, str.length());
		}
		return out_string;
	};

	if ((pos = str.find_first_of('H')) != std::string::npos)
	{
		nums_len = int(str.length()) - int(pos) - 1;
		out_string = print_string(str, pos, nums_len);
	}
	else if ((pos = str.find_first_of('R')) != std::string::npos)
	{
		if (str[pos + 2] < '7' && str[pos + 2] > '0')
		{
			nums_len = int(str.length()) - int(pos) - 2;
			out_string = print_string(str, pos, nums_len);
		}
		else
		{
			nums_len = int(str.length()) - int(pos) - 1;
			out_string = print_string(str, pos, nums_len);
		}
	}
	return out_string;
}

std::string process_hxd(const std::string& str)
{
	int nums_len = 0;
	std::string out_string(" ");
	std::string::size_type pos = std::string::npos;
	auto print_string = [](const std::string& str, const int& pos, const int& nums_len)
	{
		std::string out_string(" ");
		if (str[pos + 1]<'4' && str[pos + 1] > '0' && nums_len > 3)
		{
			switch (nums_len)
			{
			case 4:
				out_string = std::string("HXD") + str.substr(pos + 1, str.length());
				break;
			case 5:
				out_string = std::string("HXD") + str.substr(pos + 1, str.length());
				break;
			case 6:
				if (str[pos + 2] == '0') out_string = std::string("HXD") + str[pos + 1] + std::string("C") + str.substr(pos + 3, str.length());
				else out_string = "HXD" + str.substr(pos + 1, str.length());
				break;
			case 7:
				if (str[pos + 2] == '0') out_string = std::string("HXD") + str[pos + 1] + std::string("C") + str.substr(pos + 3, str.length());
				else out_string = "HXD" + str.substr(pos + 1, str.length());
				break;
			default:
				if (str[pos + 2] == '0') out_string = std::string("HXD") + str[pos + 1] + std::string("C") + str.substr(pos + 3, pos + 3 + 7);
				else out_string = std::string("HXD") + str.substr(pos + 1, str.length());
				break;
			}
		}
		return out_string;
	};

	if ((pos = str.find_first_of('D')) != std::string::npos)
	{
		nums_len = int(str.length()) - int(pos) - 1;
		out_string = print_string(str, pos, nums_len);
	}
	else if((pos = str.find_first_of('X')) != std::string::npos)
	{
		if ((str[pos + 1] == '0' || str[pos + 1] == 'C') && str[pos + 2] < '4' && str[pos + 2] > '0')
		{
			nums_len = int(str.length()) - int(pos) - 2;
			out_string = print_string(str, pos, nums_len);
		}
		else 
		{
			nums_len = int(str.length()) - int(pos) - 1;
			out_string = print_string(str, pos, nums_len);
		}
	}
	else if (str[0] < '4' && str[0] > '0')
	{
		nums_len = int(str.length());
		out_string = print_string(str, pos, nums_len);
	}	
	return out_string;
}

std::string find_head(const std::string& str, const std::string& head_str)
{
	std::vector<int> indexs;
	std::string::size_type pos;
	for (int i = 0; i < 3; i++)
	{
		pos = std::string::npos;
		if ((pos = str.find(head_str[i])) != std::string::npos) indexs.push_back(pos);
	}
	if (indexs.size() < 1)
	{
		return std::string(" ");
	}
	else if (indexs.size() > 1 && std::is_sorted(indexs.begin(), indexs.end()))
	{
		return head_str;
	}
	else if (str[indexs[0]] == head_str[1])  ///> 'R' 'H'
	{
		return head_str;
	}

	return std::string(" ");
}

TrianNumberType judge_type(const std::string& head_str)
{

	if (head_str.find('S') != std::string::npos)
	{
		return SS;
	}
	if (find_head(head_str,"CRH") != std::string(" "))
	{
		return CRH;
	}

	if (find_head(head_str, "HXD") != std::string(" "))
	{
		return HXD;
	}
	return Nothing;
}

void string_correct_completion(const std::vector<std::string>& strings, std::vector<std::string>& output_string,const int& min_len = 5)
{
	output_string.resize(strings.size(), std::string(" "));
	int count = -1;
	for (auto& str : strings)
	{
		++count;
		if (judge_all_nums(str) != 0 || str.length() < min_len) continue;				   ///> 1）字符串长度不够或全为数字

		std::string str_without_tail = remove_tail(str);							       ///> 2) 去掉尾后字符
		if (str_without_tail.length() < min_len) continue;

		std::string str_without_duplicates = remove_duplicates(str_without_tail);          ///> 3) 删除重复的字母
		if (str_without_duplicates.length() < min_len) continue;

		std::string head4          = str_without_duplicates.substr(0, 4);                  ///> 4）判断车号类型 CRH、HXD、SS
		TrianNumberType trian_type = judge_type(head4);
		if (trian_type == Nothing) continue;
		switch (trian_type)
		{
		case HXD: output_string[count] = process_hxd(str_without_duplicates);
			break;
		case CRH: output_string[count] = process_crh(str_without_duplicates);
			break;
		case SS: output_string[count] = process_ss(str_without_duplicates);
			break;
		}
		std::cout<< "\tsource:\t" << str << "\t target:\t" << output_string[count]<< std::endl;
	}
}