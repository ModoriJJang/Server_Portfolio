// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace TH_Server.TH_Packet
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct CHAT_DATA : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_23_5_26(); }
  public static CHAT_DATA GetRootAsCHAT_DATA(ByteBuffer _bb) { return GetRootAsCHAT_DATA(_bb, new CHAT_DATA()); }
  public static CHAT_DATA GetRootAsCHAT_DATA(ByteBuffer _bb, CHAT_DATA obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public CHAT_DATA __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public string Target { get { int o = __p.__offset(4); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetTargetBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetTargetBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetTargetArray() { return __p.__vector_as_array<byte>(4); }
  public TH_Server.TH_Packet.EChat ChatType { get { int o = __p.__offset(6); return o != 0 ? (TH_Server.TH_Packet.EChat)__p.bb.GetSbyte(o + __p.bb_pos) : TH_Server.TH_Packet.EChat.World; } }
  public string Message { get { int o = __p.__offset(8); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetMessageBytes() { return __p.__vector_as_span<byte>(8, 1); }
#else
  public ArraySegment<byte>? GetMessageBytes() { return __p.__vector_as_arraysegment(8); }
#endif
  public byte[] GetMessageArray() { return __p.__vector_as_array<byte>(8); }

  public static Offset<TH_Server.TH_Packet.CHAT_DATA> CreateCHAT_DATA(FlatBufferBuilder builder,
      StringOffset targetOffset = default(StringOffset),
      TH_Server.TH_Packet.EChat chat_type = TH_Server.TH_Packet.EChat.World,
      StringOffset messageOffset = default(StringOffset)) {
    builder.StartTable(3);
    CHAT_DATA.AddMessage(builder, messageOffset);
    CHAT_DATA.AddTarget(builder, targetOffset);
    CHAT_DATA.AddChatType(builder, chat_type);
    return CHAT_DATA.EndCHAT_DATA(builder);
  }

  public static void StartCHAT_DATA(FlatBufferBuilder builder) { builder.StartTable(3); }
  public static void AddTarget(FlatBufferBuilder builder, StringOffset targetOffset) { builder.AddOffset(0, targetOffset.Value, 0); }
  public static void AddChatType(FlatBufferBuilder builder, TH_Server.TH_Packet.EChat chatType) { builder.AddSbyte(1, (sbyte)chatType, 0); }
  public static void AddMessage(FlatBufferBuilder builder, StringOffset messageOffset) { builder.AddOffset(2, messageOffset.Value, 0); }
  public static Offset<TH_Server.TH_Packet.CHAT_DATA> EndCHAT_DATA(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<TH_Server.TH_Packet.CHAT_DATA>(o);
  }
}


static public class CHAT_DATAVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyString(tablePos, 4 /*Target*/, false)
      && verifier.VerifyField(tablePos, 6 /*ChatType*/, 1 /*TH_Server.TH_Packet.EChat*/, 1, false)
      && verifier.VerifyString(tablePos, 8 /*Message*/, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}

}
