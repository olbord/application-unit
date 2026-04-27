// ======================================================================
// \title  MoActionBridge.hpp
// \author nikolai
// \brief  hpp file for MoActionBridge component implementation class
// ======================================================================

#ifndef ApplicationUnit_MoActionBridge_HPP
#define ApplicationUnit_MoActionBridge_HPP

#include "ApplicationUnit/Components/MoActionBridge/MoActionBridgeComponentAc.hpp"
#include "ApplicationUnit/Types/MoActionPduSerializableAc.hpp"

namespace ApplicationUnit {

class MoActionBridge final : public MoActionBridgeComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct MoActionBridge object
    MoActionBridge(const char* const compName  //!< The component name
    );

    //! Destroy MoActionBridge object
    ~MoActionBridge();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for cmdResponseIn
    //!
    //! Receives command responses from the F Prime dispatcher
    void cmdResponseIn_handler(FwIndexType portNum,             //!< The port number
                               FwOpcodeType opCode,             //!< Command Op Code
                               U32 cmdSeq,                      //!< Command Sequence
                               const Fw::CmdResponse& response  //!< The command response argument
                               ) override;

    //! Handler implementation for moActionIn
    //!
    //! Receives raw MO Action PDU bytes from NMF via TCP
    void moActionIn_handler(FwIndexType portNum,  //!< The port number
                            Fw::Buffer& buffer,
                            const Drv::ByteStreamStatus& status) override;
};

}  // namespace ApplicationUnit

#endif
