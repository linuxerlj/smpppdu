// File  : submit_multi_resp.hpp
// Author: Dirk J. Botha <bothadj@gmail.com>
//
// This file is part of smpppdu library.
//
// The smpppdu library is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// The smpppdu library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with the smpppdu library. If not, see <http://www.gnu.org/licenses/>.

#ifndef __SMPP_PDU_SUBMIT_MULTI_RESP_HPP__
#define __SMPP_PDU_SUBMIT_MULTI_RESP_HPP__

#include "smpppdu.hpp"
#include "standard_parameters.hpp"

namespace smpp_pdu
{
  class PDU_submit_multi_resp : public SMPP_PDU
  {
    public:
      PDU_submit_multi_resp();
      PDU_submit_multi_resp(const char                  *b);
      PDU_submit_multi_resp(const PDU_submit_multi_resp &o);

      ~PDU_submit_multi_resp();

      MessageId        message_id_;
      NoUnsuccess      no_unsuccess_;
      UnsuccessSmeList unsuccess_sme_list_;

      const static int MinLength = 18;

      unsigned int getMinBodyLength() { return MinLength; }
      unsigned int getBodyLength();

    protected:
      std::string  encodeStandardParameters();
      uint8_t     *decodeStandardParameters(const uint8_t *buff);
  };
}

#endif

