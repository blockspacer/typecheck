#pragma once

#include "typecheck/literal_protocol.hpp"

namespace typecheck {
	class ExpressibleByFloatLiteral : public LiteralProtocol {
	public:
		ExpressibleByFloatLiteral() : LiteralProtocol() {}
		~ExpressibleByFloatLiteral() = default;

		std::vector<Type> getPreferredTypes() const;
		std::vector<Type> getOtherTypes() const;
	};
}