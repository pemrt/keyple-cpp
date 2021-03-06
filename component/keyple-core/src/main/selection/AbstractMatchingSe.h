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

#include <string>
#include <memory>

#include "TransmissionMode.h"

/* Common */
#include "KeypleCoreExport.h"

/* Forward class declarations  */
namespace keyple {
namespace core {
namespace seproxy {
namespace message {
class SeResponse;
}
}
}
}
namespace keyple {
namespace core {
namespace seproxy {
namespace message {
class SelectionStatus;
}
}
}
}

namespace keyple {
namespace core {
namespace selection {

using namespace keyple::core::seproxy::message;
using namespace keyple::core::seproxy::protocol;

/**
 * AbstractMatchingSe is the class to manage the elements of the result of a
 * selection.
 */
class KEYPLECORE_API AbstractMatchingSe
: public std::enable_shared_from_this<AbstractMatchingSe> {
public:
    /**
     * Constructor.
     *
     * @param selectionResponse the response from the SE
     * @param transmissionMode the transmission mode, contact or contactless
     * @param extraInfo information string
     */
    AbstractMatchingSe(std::shared_ptr<SeResponse> selectionResponse,
                       TransmissionMode transmissionMode,
                       const std::string& extraInfo);

    /**
     *
     */
    virtual ~AbstractMatchingSe()
    {
    }

    /**
     * Indicates whether the current SE has been identified as selected: the
     * logical channel is open and the selection process returned either a FCI
     * or an ATR
     *
     * @return true or false
     */
    bool isSelected();

    /**
     * @return the SE {@link SelectionStatus}
     */
    virtual std::shared_ptr<SelectionStatus> getSelectionStatus();

    /**
     * @return the SE {@link TransmissionMode} (contacts or contactless)
     */
    virtual TransmissionMode getTransmissionMode() const;

    /**
     * @return the selection extra info string
     */
    virtual std::string getSelectionExtraInfo();

	/**
	 *
	 */
    friend KEYPLECORE_API std::ostream& operator<<(
        std::ostream& os, const AbstractMatchingSe& ams);

private:
    /**
     *
     */
    const std::shared_ptr<SeResponse> selectionResponse;

    /**
     *
     */
    const TransmissionMode transmissionMode;

    /**
     *
     */
    std::shared_ptr<SelectionStatus> selectionStatus;

    /**
     *
     */
    const std::string selectionExtraInfo;
};

}
}
}
