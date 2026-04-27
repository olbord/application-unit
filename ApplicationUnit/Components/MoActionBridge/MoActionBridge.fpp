module ApplicationUnit {

    @ Handles the API calls from Nanosats MO Framework (NMF)
    active component MoActionBridge {

        # ----------------------------------------------------------------------
        # Special ports
        # ----------------------------------------------------------------------

        @ Receives raw MO Action PDU bytes from NMF via TCP
        async input port moActionIn: Drv.ByteStreamData

        @ Sends decoded commands to the F Prime dispatcher
        output port cmdOut: Fw.Cmd

        @ Receives command responses from the F Prime dispatcher
        sync input port cmdResponseIn: Fw.CmdResponse

        # ----------------------------------------------------------------------
        # General ports
        # ----------------------------------------------------------------------

        @ Command receive
        command recv port cmdIn

        @ Command registration
        command reg port cmdRegOut

        @ Command response
        command resp port cmdResponseOut

        @ Event
        event port eventOut

        @ Telemetry
        telemetry port tlmOut

        @ Text event
        text event port textEventOut

        @ Time get
        time get port timeGetOut

        # ----------------------------------------------------------------------
        # Commands
        # ----------------------------------------------------------------------
        

        # ----------------------------------------------------------------------
        # Events
        # ----------------------------------------------------------------------

        event ActionDispatched(
            actionId: U16
        ) severity activity low id 0 format "MO Action {} dispatched" 

        # ----------------------------------------------------------------------
        # Telemetry
        # ----------------------------------------------------------------------
        
        telemetry ActionsReceived: U32 id 0
        telemetry ActionsDispatched: U32 id 1
        telemetry DecodeErrors: U32 id 2

    }
}
