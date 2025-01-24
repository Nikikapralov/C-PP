#include<iostream>
#include<thread>

void main() {
	std::cout << std::thread::hardware_concurrency();
};