/******************************************************************************
 * Copyright (c) 2018 Calypso Networks Association                            *
 * https://www.calypsonet-asso.org/                                           *
 *                                                                            *
 * See the NOTICE file(s) distributed with this work for additional           *
 * information regarding copyright ownership.                                 *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the Eclipse Public License 2.0 which is available at              *
 * http://www.eclipse.org/legal/epl-2.0                                       *
 *                                                                            *
 * SPDX-License-Identifier: EPL-2.0                                           *
 ******************************************************************************/

#pragma once

#include <vector>
#include <memory>

/* Core */
#include "AbstractSamResponseParser.h"

#include "KeypleCalypsoExport.h"

namespace keyple {
namespace calypso {
namespace command {
namespace sam {
namespace parser {
namespace security {

using namespace keyple::calypso::command::sam;
using namespace keyple::core::seproxy::message;

/**
 * SAM get challenge. See specs: Calypso / Page 108 / 9.5.4 - Get challenge
 */
class KEYPLECALYPSO_API SamGetChallengeRespPars
: public AbstractSamResponseParser {
public:
    /**
     * Instantiates a new SamGetChallengeRespPars .
     *
     * @param response of the SamGetChallengeCmdBuild
     */
    SamGetChallengeRespPars(std::shared_ptr<ApduResponse> response);

    /**
     *
     */
    virtual ~SamGetChallengeRespPars()
    {
    }

    /**
     * Gets the challenge.
     *
     * @return the challenge
     */
    virtual std::vector<uint8_t> getChallenge() const;

protected:
    /**
     *
     */
    std::shared_ptr<SamGetChallengeRespPars> shared_from_this()
    {
        return std::static_pointer_cast<SamGetChallengeRespPars>(
            AbstractSamResponseParser::shared_from_this());
    }
};

}
}
}
}
}
}
