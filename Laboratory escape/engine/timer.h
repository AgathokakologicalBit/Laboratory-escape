#pragma once


#include <string>
#include <utility>
#include <chrono>
#include <iostream>
#include <iomanip>


class Timer
{
public:
	std::string const name;

private:
	std::chrono::high_resolution_clock::time_point start;

public:
	explicit Timer(std::string name_)
		: name(std::move(name_))
		, start(std::chrono::high_resolution_clock::now())
	{ }

	~Timer()
	{
		using namespace std::chrono;
		auto duration = high_resolution_clock::now() - start;

		auto ms = duration_cast<milliseconds>(duration).count();
		auto us = duration_cast<microseconds>(duration).count() % 1000;

		double passed = ms + us / 1000.;

		std::cout
			<< "[Timer] " << name << ": "
			<< std::setprecision(3) << passed << " ms" << '\n';
	}
};
