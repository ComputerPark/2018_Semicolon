#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <Windows.h>	 //�������
#include <ctime>
#include "disclaimer.h"
#include "keydef.h"
#include "colors.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") //���� ���� �Լ���

#include ".//inc//fmod.hpp" //fmod c++ header
#pragma comment( lib, ".\\lib\\fmodex_vc.lib" ) // fmod library
#include "sndenum.h"
#include <tchar.h>



using namespace FMOD;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)