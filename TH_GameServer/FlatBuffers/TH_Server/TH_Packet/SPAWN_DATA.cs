// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace TH_Server.TH_Packet
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct SPAWN_DATA : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_23_5_26(); }
  public static SPAWN_DATA GetRootAsSPAWN_DATA(ByteBuffer _bb) { return GetRootAsSPAWN_DATA(_bb, new SPAWN_DATA()); }
  public static SPAWN_DATA GetRootAsSPAWN_DATA(ByteBuffer _bb, SPAWN_DATA obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public SPAWN_DATA __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public string Owner { get { int o = __p.__offset(4); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetOwnerBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetOwnerBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetOwnerArray() { return __p.__vector_as_array<byte>(4); }
  public int Networkid { get { int o = __p.__offset(6); return o != 0 ? __p.bb.GetInt(o + __p.bb_pos) : (int)0; } }
  public TH_Server.TH_Packet.Vector3? Position { get { int o = __p.__offset(8); return o != 0 ? (TH_Server.TH_Packet.Vector3?)(new TH_Server.TH_Packet.Vector3()).__assign(o + __p.bb_pos, __p.bb) : null; } }
  public string Objecttype { get { int o = __p.__offset(10); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetObjecttypeBytes() { return __p.__vector_as_span<byte>(10, 1); }
#else
  public ArraySegment<byte>? GetObjecttypeBytes() { return __p.__vector_as_arraysegment(10); }
#endif
  public byte[] GetObjecttypeArray() { return __p.__vector_as_array<byte>(10); }

  public static void StartSPAWN_DATA(FlatBufferBuilder builder) { builder.StartTable(4); }
  public static void AddOwner(FlatBufferBuilder builder, StringOffset ownerOffset) { builder.AddOffset(0, ownerOffset.Value, 0); }
  public static void AddNetworkid(FlatBufferBuilder builder, int networkid) { builder.AddInt(1, networkid, 0); }
  public static void AddPosition(FlatBufferBuilder builder, Offset<TH_Server.TH_Packet.Vector3> positionOffset) { builder.AddStruct(2, positionOffset.Value, 0); }
  public static void AddObjecttype(FlatBufferBuilder builder, StringOffset objecttypeOffset) { builder.AddOffset(3, objecttypeOffset.Value, 0); }
  public static Offset<TH_Server.TH_Packet.SPAWN_DATA> EndSPAWN_DATA(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<TH_Server.TH_Packet.SPAWN_DATA>(o);
  }
}


static public class SPAWN_DATAVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyString(tablePos, 4 /*Owner*/, false)
      && verifier.VerifyField(tablePos, 6 /*Networkid*/, 4 /*int*/, 4, false)
      && verifier.VerifyField(tablePos, 8 /*Position*/, 12 /*TH_Server.TH_Packet.Vector3*/, 4, false)
      && verifier.VerifyString(tablePos, 10 /*Objecttype*/, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}

}
