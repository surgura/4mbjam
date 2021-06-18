#pragma once

namespace LSystem
{

struct NoCopy
{
	NoCopy() = default;

	NoCopy(const NoCopy&) = delete;

	NoCopy& operator=(const NoCopy&) = delete;
};

} // namespace LSystem
