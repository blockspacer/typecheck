#pragma once
#include <vector>
#include <map>
#include <deque>
#include <numeric>

#include <typecheck_protos/type.pb.h>
#include <typecheck_protos/constraint.pb.h>

#include "constraint_pass.hpp"

namespace typecheck {
	class TypeManager;
	class TypeSolver {
	private:
		std::map<std::size_t, std::vector<std::size_t>> typeRefGraph;
		std::map<std::string, std::vector<FunctionDefinition>> funcOverloads;

		ConstraintPass last_pass;

		// Implementations found in `type_solver+init_pass.cpp`
		void InitPasses(typecheck::TypeManager* manager);
        void RemoveDuplicates(typecheck::TypeManager* manager);

		// Implementations found in `type_solver+solver.cpp`
		void DoPass(ConstraintPass* pass, const TypeManager* manager) const;
		void DoPass_internal(ConstraintPass* pass, std::deque<std::size_t>/* this is a copy */ indexes, const TypeManager* manager, const std::size_t& prev_failed, const std::size_t& prev_emplaced) const;

	public:
		TypeSolver();
		~TypeSolver() = default;

		bool solve(const TypeManager* manager);
		Type getResolvedType(const TypeVar& _typeVar) const;
	};
}
