#include <cstdlib>

#include <glm/gtc/random.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <LSystem/LSystem.hpp>



namespace LSystem
{

	RandomLengthOperation::RandomLengthOperation(OperationOwner* owner, std::string_view name)
		: Operation(owner, name)
	{

	}

	std::vector<Instruction*> RandomLengthOperation::Apply(const std::vector<Instruction*>& apply_to, LSystem& lsystem)
	{
		std::srand(0);

		for (auto& i : apply_to)
		{
			i->data->length = glm::linearRand<float>(min, max);
		}
		return {};
	}

	const std::string& RandomLengthOperation::Description() const
	{
		static const std::string type_name_friendly = "Random Length";
		return type_name_friendly;
	}

}