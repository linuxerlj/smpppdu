// File  : deliver_sm.hpp
// Author: Dirk J. Botha <bothadj@gmail.com>
//
// This file is part of smpp_pdu library.
//
// The smpp_pdu library is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// The smpp_pdu library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with the smpp_pdu library. If not, see <http://www.gnu.org/licenses/>.

#ifndef __SMPP_PDU_DELIVER_SM_HPP__
#define __SMPP_PDU_DELIVER_SM_HPP__

#include <sstream>
#include "smpp_pdu.hpp"
#include "standard_parameters.hpp"

namespace smpp_pdu
{
  class PDU_deliver_sm : public SMPP_PDU
  {
    public:
      PDU_deliver_sm();
      PDU_deliver_sm(const char           *b);
      PDU_deliver_sm(const PDU_deliver_sm &o);

      ~PDU_deliver_sm();

      const static int     MinLength = 33;
      ServiceType          service_type;
      NormalSmeAddress     source_addr;
      NormalSmeAddress     destination_addr;
      EsmClass             esm_class;
      ProtocolId           protocol_id;
      PriorityFlag         priority_flag;
      Time                 schedule_delivery_time;
      Time                 validity_period;
      RegisteredDelivery   registered_delivery;
      ReplaceIfPresentFlag replace_if_present_flag;
      DataCoding           data_coding;
      SmDefaultMsgId       sm_default_msg_id;
      ShortMessage         short_message;

      unsigned int getMinBodyLength() { return MinLength; }
      unsigned int getBodyLength();

    protected:
      std::string  encodeStandardParameters();
      uint8_t     *decodeStandardParameters(const uint8_t *buff);
  };
}

#endif

