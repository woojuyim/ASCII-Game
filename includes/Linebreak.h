#ifndef LINEBREAK_H
#define LINEBREAK_H
#pragma once

#include <iostream>
#include <chrono>	
#include <thread>
using namespace std::chrono;
void linebreak() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\n==============================================================================================\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

}
void sleep() {
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

#endif