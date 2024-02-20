// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Packet.proto

#include "Packet.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace TH_SERVER {
constexpr PACKET::PACKET(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : data_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , packettype_(0)
{}
struct PACKETDefaultTypeInternal {
  constexpr PACKETDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PACKETDefaultTypeInternal() {}
  union {
    PACKET _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PACKETDefaultTypeInternal _PACKET_default_instance_;
constexpr TH_PACKET::TH_PACKET(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : packet_()
  , clientid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct TH_PACKETDefaultTypeInternal {
  constexpr TH_PACKETDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TH_PACKETDefaultTypeInternal() {}
  union {
    TH_PACKET _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TH_PACKETDefaultTypeInternal _TH_PACKET_default_instance_;
}  // namespace TH_SERVER
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Packet_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_Packet_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Packet_2eproto = nullptr;

const uint32_t TableStruct_Packet_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::TH_SERVER::PACKET, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::TH_SERVER::PACKET, packettype_),
  PROTOBUF_FIELD_OFFSET(::TH_SERVER::PACKET, data_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::TH_SERVER::TH_PACKET, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::TH_SERVER::TH_PACKET, clientid_),
  PROTOBUF_FIELD_OFFSET(::TH_SERVER::TH_PACKET, packet_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::TH_SERVER::PACKET)},
  { 8, -1, -1, sizeof(::TH_SERVER::TH_PACKET)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::TH_SERVER::_PACKET_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::TH_SERVER::_TH_PACKET_default_instance_),
};

const char descriptor_table_protodef_Packet_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014Packet.proto\022\tTH_SERVER\"B\n\006PACKET\022*\n\np"
  "ackettype\030\001 \001(\0162\026.TH_SERVER.PACKET_TYPE\022"
  "\014\n\004Data\030\002 \001(\t\"@\n\tTH_PACKET\022\020\n\010clientid\030\001"
  " \001(\t\022!\n\006packet\030\002 \003(\0132\021.TH_SERVER.PACKET*"
  "0\n\013PACKET_TYPE\022\010\n\004CHAT\020\000\022\n\n\006PLAYER\020\001\022\013\n\007"
  "MONSTER\020\002b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Packet_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Packet_2eproto = {
  false, false, 217, descriptor_table_protodef_Packet_2eproto, "Packet.proto", 
  &descriptor_table_Packet_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_Packet_2eproto::offsets,
  file_level_metadata_Packet_2eproto, file_level_enum_descriptors_Packet_2eproto, file_level_service_descriptors_Packet_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Packet_2eproto_getter() {
  return &descriptor_table_Packet_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Packet_2eproto(&descriptor_table_Packet_2eproto);
namespace TH_SERVER {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PACKET_TYPE_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Packet_2eproto);
  return file_level_enum_descriptors_Packet_2eproto[0];
}
bool PACKET_TYPE_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class PACKET::_Internal {
 public:
};

PACKET::PACKET(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:TH_SERVER.PACKET)
}
PACKET::PACKET(const PACKET& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_data().empty()) {
    data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_data(), 
      GetArenaForAllocation());
  }
  packettype_ = from.packettype_;
  // @@protoc_insertion_point(copy_constructor:TH_SERVER.PACKET)
}

inline void PACKET::SharedCtor() {
data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
packettype_ = 0;
}

PACKET::~PACKET() {
  // @@protoc_insertion_point(destructor:TH_SERVER.PACKET)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void PACKET::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void PACKET::ArenaDtor(void* object) {
  PACKET* _this = reinterpret_cast< PACKET* >(object);
  (void)_this;
}
void PACKET::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PACKET::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void PACKET::Clear() {
// @@protoc_insertion_point(message_clear_start:TH_SERVER.PACKET)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.ClearToEmpty();
  packettype_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PACKET::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .TH_SERVER.PACKET_TYPE packettype = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_packettype(static_cast<::TH_SERVER::PACKET_TYPE>(val));
        } else
          goto handle_unusual;
        continue;
      // string Data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_data();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "TH_SERVER.PACKET.Data"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PACKET::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:TH_SERVER.PACKET)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .TH_SERVER.PACKET_TYPE packettype = 1;
  if (this->_internal_packettype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_packettype(), target);
  }

  // string Data = 2;
  if (!this->_internal_data().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_data().data(), static_cast<int>(this->_internal_data().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "TH_SERVER.PACKET.Data");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TH_SERVER.PACKET)
  return target;
}

size_t PACKET::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TH_SERVER.PACKET)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string Data = 2;
  if (!this->_internal_data().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_data());
  }

  // .TH_SERVER.PACKET_TYPE packettype = 1;
  if (this->_internal_packettype() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_packettype());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PACKET::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    PACKET::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PACKET::GetClassData() const { return &_class_data_; }

void PACKET::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<PACKET *>(to)->MergeFrom(
      static_cast<const PACKET &>(from));
}


void PACKET::MergeFrom(const PACKET& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TH_SERVER.PACKET)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_data().empty()) {
    _internal_set_data(from._internal_data());
  }
  if (from._internal_packettype() != 0) {
    _internal_set_packettype(from._internal_packettype());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PACKET::CopyFrom(const PACKET& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TH_SERVER.PACKET)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PACKET::IsInitialized() const {
  return true;
}

void PACKET::InternalSwap(PACKET* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &data_, lhs_arena,
      &other->data_, rhs_arena
  );
  swap(packettype_, other->packettype_);
}

::PROTOBUF_NAMESPACE_ID::Metadata PACKET::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Packet_2eproto_getter, &descriptor_table_Packet_2eproto_once,
      file_level_metadata_Packet_2eproto[0]);
}

// ===================================================================

class TH_PACKET::_Internal {
 public:
};

TH_PACKET::TH_PACKET(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  packet_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:TH_SERVER.TH_PACKET)
}
TH_PACKET::TH_PACKET(const TH_PACKET& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      packet_(from.packet_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  clientid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    clientid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_clientid().empty()) {
    clientid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_clientid(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:TH_SERVER.TH_PACKET)
}

inline void TH_PACKET::SharedCtor() {
clientid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  clientid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

TH_PACKET::~TH_PACKET() {
  // @@protoc_insertion_point(destructor:TH_SERVER.TH_PACKET)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void TH_PACKET::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  clientid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void TH_PACKET::ArenaDtor(void* object) {
  TH_PACKET* _this = reinterpret_cast< TH_PACKET* >(object);
  (void)_this;
}
void TH_PACKET::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TH_PACKET::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void TH_PACKET::Clear() {
// @@protoc_insertion_point(message_clear_start:TH_SERVER.TH_PACKET)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  packet_.Clear();
  clientid_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TH_PACKET::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string clientid = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_clientid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "TH_SERVER.TH_PACKET.clientid"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .TH_SERVER.PACKET packet = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_packet(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* TH_PACKET::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:TH_SERVER.TH_PACKET)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string clientid = 1;
  if (!this->_internal_clientid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_clientid().data(), static_cast<int>(this->_internal_clientid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "TH_SERVER.TH_PACKET.clientid");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_clientid(), target);
  }

  // repeated .TH_SERVER.PACKET packet = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_packet_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_packet(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TH_SERVER.TH_PACKET)
  return target;
}

size_t TH_PACKET::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TH_SERVER.TH_PACKET)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .TH_SERVER.PACKET packet = 2;
  total_size += 1UL * this->_internal_packet_size();
  for (const auto& msg : this->packet_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string clientid = 1;
  if (!this->_internal_clientid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_clientid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData TH_PACKET::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    TH_PACKET::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*TH_PACKET::GetClassData() const { return &_class_data_; }

void TH_PACKET::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<TH_PACKET *>(to)->MergeFrom(
      static_cast<const TH_PACKET &>(from));
}


void TH_PACKET::MergeFrom(const TH_PACKET& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TH_SERVER.TH_PACKET)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  packet_.MergeFrom(from.packet_);
  if (!from._internal_clientid().empty()) {
    _internal_set_clientid(from._internal_clientid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void TH_PACKET::CopyFrom(const TH_PACKET& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TH_SERVER.TH_PACKET)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TH_PACKET::IsInitialized() const {
  return true;
}

void TH_PACKET::InternalSwap(TH_PACKET* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  packet_.InternalSwap(&other->packet_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &clientid_, lhs_arena,
      &other->clientid_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata TH_PACKET::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Packet_2eproto_getter, &descriptor_table_Packet_2eproto_once,
      file_level_metadata_Packet_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace TH_SERVER
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::TH_SERVER::PACKET* Arena::CreateMaybeMessage< ::TH_SERVER::PACKET >(Arena* arena) {
  return Arena::CreateMessageInternal< ::TH_SERVER::PACKET >(arena);
}
template<> PROTOBUF_NOINLINE ::TH_SERVER::TH_PACKET* Arena::CreateMaybeMessage< ::TH_SERVER::TH_PACKET >(Arena* arena) {
  return Arena::CreateMessageInternal< ::TH_SERVER::TH_PACKET >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
