// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include "../lib/public.h"
#include "../dll2/public.h"

int main()
{
  std::cout << "static_lib::get_value(1) = " << static_lib::get_value(1) << std::endl;
  std::cout << "dll with implib get_value(1) = " << get_value(1) << std::endl;;

  auto module_handle = LoadLibraryA("dynamic_library.dll");
  auto address_of_get_value = GetProcAddress(module_handle, "get_value");
  auto pointer_to_get_value = reinterpret_cast<double(*)(int)>(address_of_get_value);
  std::cout << "dll get_value(1) = " << pointer_to_get_value(1) << std::endl;
}