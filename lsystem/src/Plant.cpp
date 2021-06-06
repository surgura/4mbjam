#include <LSystem/Plant.hpp>

#include <LSystem/Operations/ColoringOperation.hpp>
#include <LSystem/Operations/ExtrudeOperation.hpp>
#include <LSystem/Operations/FanOperation.hpp>
#include <LSystem/Operations/PhyllotaxisOperation.hpp>
#include <LSystem/Operations/ForkOperation.hpp>



namespace LSystem
{

	ColoringOperation* Plant::CreateColoringOperation(std::string_view name)
	{
		m_operationsOwned.push_back(std::make_unique<ColoringOperation>(this, name));
		return static_cast<ColoringOperation*>(m_operationsOwned.back().get());
	}

	ExtrudeOperation* Plant::CreateExtrudeOperation(std::string_view name)
	{
		m_operationsOwned.push_back(std::make_unique<ExtrudeOperation>(this, name));
		return static_cast<ExtrudeOperation*>(m_operationsOwned.back().get());
	}

	FanOperation* Plant::CreateFanOperation(std::string_view name)
	{
		m_operationsOwned.push_back(std::make_unique<FanOperation>(this, name));
		return static_cast<FanOperation*>(m_operationsOwned.back().get());
	}

	PhyllotaxisOperation* Plant::CreatePhyllotaxisOperation(std::string_view name)
	{
		m_operationsOwned.push_back(std::make_unique<PhyllotaxisOperation>(this, name));
		return static_cast<PhyllotaxisOperation*>(m_operationsOwned.back().get());
	}

	ForkOperation* Plant::CreateForkOperation(std::string_view name)
	{
		m_operationsOwned.push_back(std::make_unique<ForkOperation>(this, name));
		return static_cast<ForkOperation*>(m_operationsOwned.back().get());
	}

	bool Plant::CreateConnection(const Operation* output, const Operation* input)
	{
		if (m_connections.count(Connection{ output, input }) == 0)
		{
			m_connections.emplace(Connection{ output, input });
			return true;
		}
		return false;
	}

	bool Plant::AreConnected(const Operation* output, const Operation* input) const
	{
		return m_connections.count(Connection{ output, input });
	}

	const std::unordered_set<Connection>& Plant::Connections() const
	{
		return m_connections;
	}

}
