module ApplicationUnit {

  array MoActionArgs = [64] U8

  struct MoActionPdu {
    urgency:  U8
    srcNode:  U8
    dstNode:  U8
    srcPort:  U8
    dstPort:  U8
    flags:    U8
    actionId: U16
    argLen:   U8
    argBytes: MoActionArgs
  } default {
    urgency  = 2,
    srcNode  = 0,
    dstNode  = 0,
    srcPort  = 0,
    dstPort  = 10,
    flags    = 0,
    actionId = 0,
    argLen   = 0,
    argBytes = [0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0]
  }

}
