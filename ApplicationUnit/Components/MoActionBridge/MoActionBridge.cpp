// ======================================================================
// \title  MoActionBridge.cpp
// \author nikolai
// \brief  cpp file for MoActionBridge component implementation class
// ======================================================================

#include "ApplicationUnit/Components/MoActionBridge/MoActionBridge.hpp"

namespace ApplicationUnit {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

MoActionBridge ::MoActionBridge(const char* const compName) : MoActionBridgeComponentBase(compName) {}

MoActionBridge ::~MoActionBridge() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void MoActionBridge ::cmdResponseIn_handler(FwIndexType portNum,
                                            FwOpcodeType opCode,
                                            U32 cmdSeq,
                                            const Fw::CmdResponse& response) {
    // TODO
}

void MoActionBridge ::moActionIn_handler(FwIndexType portNum, Fw::Buffer& buffer, const Drv::ByteStreamStatus& status) {
    if (status != Drv::ByteStreamStatus::RECV_OK) {
        return;
    } 

    MoActionPdu pdu;
    this->log_ACTIVITY_LO_ActionDispatched(pdu.get_actionId());
}

}  // namespace ApplicationUnit
