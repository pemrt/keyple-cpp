/********************************************************************************
* Copyright (c) 2019 Calypso Networks Association https://www.calypsonet-asso.org/
*
* See the NOTICE file(s) distributed with this work for additional information regarding copyright
* ownership.
*
* This program and the accompanying materials are made available under the terms of the Eclipse
* Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0
*
* SPDX-License-Identifier: EPL-2.0
********************************************************************************/

#include "SeProtocol.h"

namespace keyple {
namespace core {
namespace seproxy {
namespace protocol {

int SeProtocol::nextOrdinal = 0;

std::ostream& operator<<(std::ostream& os, const SeProtocol& se)
{
    os << "SEPROTOCOL {"
	   << "NAME = " << se.getName() << ", "
	   << "ORDINAL" << se.ordinalValue
	   << "}";

    return os;
}

}
}
}
}
