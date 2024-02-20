// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Packet.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Packet_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Packet_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019006 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Packet_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Packet_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Packet_2eproto;
namespace TH_SERVER {
class PACKET;
struct PACKETDefaultTypeInternal;
extern PACKETDefaultTypeInternal _PACKET_default_instance_;
class TH_PACKET;
struct TH_PACKETDefaultTypeInternal;
extern TH_PACKETDefaultTypeInternal _TH_PACKET_default_instance_;
}  // namespace TH_SERVER
PROTOBUF_NAMESPACE_OPEN
template<> ::TH_SERVER::PACKET* Arena::CreateMaybeMessage<::TH_SERVER::PACKET>(Arena*);
template<> ::TH_SERVER::TH_PACKET* Arena::CreateMaybeMessage<::TH_SERVER::TH_PACKET>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace TH_SERVER {

enum PACKET_TYPE : int {
  CHAT = 0,
  PLAYER = 1,
  MONSTER = 2,
  PACKET_TYPE_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PACKET_TYPE_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PACKET_TYPE_IsValid(int value);
constexpr PACKET_TYPE PACKET_TYPE_MIN = CHAT;
constexpr PACKET_TYPE PACKET_TYPE_MAX = MONSTER;
constexpr int PACKET_TYPE_ARRAYSIZE = PACKET_TYPE_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PACKET_TYPE_descriptor();
template<typename T>
inline const std::string& PACKET_TYPE_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PACKET_TYPE>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PACKET_TYPE_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PACKET_TYPE_descriptor(), enum_t_value);
}
inline bool PACKET_TYPE_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PACKET_TYPE* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PACKET_TYPE>(
    PACKET_TYPE_descriptor(), name, value);
}
// ===================================================================

class PACKET final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TH_SERVER.PACKET) */ {
 public:
  inline PACKET() : PACKET(nullptr) {}
  ~PACKET() override;
  explicit constexpr PACKET(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PACKET(const PACKET& from);
  PACKET(PACKET&& from) noexcept
    : PACKET() {
    *this = ::std::move(from);
  }

  inline PACKET& operator=(const PACKET& from) {
    CopyFrom(from);
    return *this;
  }
  inline PACKET& operator=(PACKET&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PACKET& default_instance() {
    return *internal_default_instance();
  }
  static inline const PACKET* internal_default_instance() {
    return reinterpret_cast<const PACKET*>(
               &_PACKET_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PACKET& a, PACKET& b) {
    a.Swap(&b);
  }
  inline void Swap(PACKET* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PACKET* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PACKET* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PACKET>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PACKET& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PACKET& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PACKET* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TH_SERVER.PACKET";
  }
  protected:
  explicit PACKET(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDataFieldNumber = 2,
    kPackettypeFieldNumber = 1,
  };
  // string Data = 2;
  void clear_data();
  const std::string& data() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_data(ArgT0&& arg0, ArgT... args);
  std::string* mutable_data();
  PROTOBUF_NODISCARD std::string* release_data();
  void set_allocated_data(std::string* data);
  private:
  const std::string& _internal_data() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_data(const std::string& value);
  std::string* _internal_mutable_data();
  public:

  // .TH_SERVER.PACKET_TYPE packettype = 1;
  void clear_packettype();
  ::TH_SERVER::PACKET_TYPE packettype() const;
  void set_packettype(::TH_SERVER::PACKET_TYPE value);
  private:
  ::TH_SERVER::PACKET_TYPE _internal_packettype() const;
  void _internal_set_packettype(::TH_SERVER::PACKET_TYPE value);
  public:

  // @@protoc_insertion_point(class_scope:TH_SERVER.PACKET)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
  int packettype_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Packet_2eproto;
};
// -------------------------------------------------------------------

class TH_PACKET final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TH_SERVER.TH_PACKET) */ {
 public:
  inline TH_PACKET() : TH_PACKET(nullptr) {}
  ~TH_PACKET() override;
  explicit constexpr TH_PACKET(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TH_PACKET(const TH_PACKET& from);
  TH_PACKET(TH_PACKET&& from) noexcept
    : TH_PACKET() {
    *this = ::std::move(from);
  }

  inline TH_PACKET& operator=(const TH_PACKET& from) {
    CopyFrom(from);
    return *this;
  }
  inline TH_PACKET& operator=(TH_PACKET&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TH_PACKET& default_instance() {
    return *internal_default_instance();
  }
  static inline const TH_PACKET* internal_default_instance() {
    return reinterpret_cast<const TH_PACKET*>(
               &_TH_PACKET_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(TH_PACKET& a, TH_PACKET& b) {
    a.Swap(&b);
  }
  inline void Swap(TH_PACKET* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TH_PACKET* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TH_PACKET* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TH_PACKET>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TH_PACKET& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const TH_PACKET& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TH_PACKET* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TH_SERVER.TH_PACKET";
  }
  protected:
  explicit TH_PACKET(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPacketFieldNumber = 2,
    kClientidFieldNumber = 1,
  };
  // repeated .TH_SERVER.PACKET packet = 2;
  int packet_size() const;
  private:
  int _internal_packet_size() const;
  public:
  void clear_packet();
  ::TH_SERVER::PACKET* mutable_packet(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TH_SERVER::PACKET >*
      mutable_packet();
  private:
  const ::TH_SERVER::PACKET& _internal_packet(int index) const;
  ::TH_SERVER::PACKET* _internal_add_packet();
  public:
  const ::TH_SERVER::PACKET& packet(int index) const;
  ::TH_SERVER::PACKET* add_packet();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TH_SERVER::PACKET >&
      packet() const;

  // string clientid = 1;
  void clear_clientid();
  const std::string& clientid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_clientid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_clientid();
  PROTOBUF_NODISCARD std::string* release_clientid();
  void set_allocated_clientid(std::string* clientid);
  private:
  const std::string& _internal_clientid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_clientid(const std::string& value);
  std::string* _internal_mutable_clientid();
  public:

  // @@protoc_insertion_point(class_scope:TH_SERVER.TH_PACKET)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TH_SERVER::PACKET > packet_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr clientid_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Packet_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PACKET

// .TH_SERVER.PACKET_TYPE packettype = 1;
inline void PACKET::clear_packettype() {
  packettype_ = 0;
}
inline ::TH_SERVER::PACKET_TYPE PACKET::_internal_packettype() const {
  return static_cast< ::TH_SERVER::PACKET_TYPE >(packettype_);
}
inline ::TH_SERVER::PACKET_TYPE PACKET::packettype() const {
  // @@protoc_insertion_point(field_get:TH_SERVER.PACKET.packettype)
  return _internal_packettype();
}
inline void PACKET::_internal_set_packettype(::TH_SERVER::PACKET_TYPE value) {
  
  packettype_ = value;
}
inline void PACKET::set_packettype(::TH_SERVER::PACKET_TYPE value) {
  _internal_set_packettype(value);
  // @@protoc_insertion_point(field_set:TH_SERVER.PACKET.packettype)
}

// string Data = 2;
inline void PACKET::clear_data() {
  data_.ClearToEmpty();
}
inline const std::string& PACKET::data() const {
  // @@protoc_insertion_point(field_get:TH_SERVER.PACKET.Data)
  return _internal_data();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PACKET::set_data(ArgT0&& arg0, ArgT... args) {
 
 data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:TH_SERVER.PACKET.Data)
}
inline std::string* PACKET::mutable_data() {
  std::string* _s = _internal_mutable_data();
  // @@protoc_insertion_point(field_mutable:TH_SERVER.PACKET.Data)
  return _s;
}
inline const std::string& PACKET::_internal_data() const {
  return data_.Get();
}
inline void PACKET::_internal_set_data(const std::string& value) {
  
  data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PACKET::_internal_mutable_data() {
  
  return data_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PACKET::release_data() {
  // @@protoc_insertion_point(field_release:TH_SERVER.PACKET.Data)
  return data_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void PACKET::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    
  } else {
    
  }
  data_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (data_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:TH_SERVER.PACKET.Data)
}

// -------------------------------------------------------------------

// TH_PACKET

// string clientid = 1;
inline void TH_PACKET::clear_clientid() {
  clientid_.ClearToEmpty();
}
inline const std::string& TH_PACKET::clientid() const {
  // @@protoc_insertion_point(field_get:TH_SERVER.TH_PACKET.clientid)
  return _internal_clientid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void TH_PACKET::set_clientid(ArgT0&& arg0, ArgT... args) {
 
 clientid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:TH_SERVER.TH_PACKET.clientid)
}
inline std::string* TH_PACKET::mutable_clientid() {
  std::string* _s = _internal_mutable_clientid();
  // @@protoc_insertion_point(field_mutable:TH_SERVER.TH_PACKET.clientid)
  return _s;
}
inline const std::string& TH_PACKET::_internal_clientid() const {
  return clientid_.Get();
}
inline void TH_PACKET::_internal_set_clientid(const std::string& value) {
  
  clientid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* TH_PACKET::_internal_mutable_clientid() {
  
  return clientid_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* TH_PACKET::release_clientid() {
  // @@protoc_insertion_point(field_release:TH_SERVER.TH_PACKET.clientid)
  return clientid_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void TH_PACKET::set_allocated_clientid(std::string* clientid) {
  if (clientid != nullptr) {
    
  } else {
    
  }
  clientid_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), clientid,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (clientid_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    clientid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:TH_SERVER.TH_PACKET.clientid)
}

// repeated .TH_SERVER.PACKET packet = 2;
inline int TH_PACKET::_internal_packet_size() const {
  return packet_.size();
}
inline int TH_PACKET::packet_size() const {
  return _internal_packet_size();
}
inline void TH_PACKET::clear_packet() {
  packet_.Clear();
}
inline ::TH_SERVER::PACKET* TH_PACKET::mutable_packet(int index) {
  // @@protoc_insertion_point(field_mutable:TH_SERVER.TH_PACKET.packet)
  return packet_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TH_SERVER::PACKET >*
TH_PACKET::mutable_packet() {
  // @@protoc_insertion_point(field_mutable_list:TH_SERVER.TH_PACKET.packet)
  return &packet_;
}
inline const ::TH_SERVER::PACKET& TH_PACKET::_internal_packet(int index) const {
  return packet_.Get(index);
}
inline const ::TH_SERVER::PACKET& TH_PACKET::packet(int index) const {
  // @@protoc_insertion_point(field_get:TH_SERVER.TH_PACKET.packet)
  return _internal_packet(index);
}
inline ::TH_SERVER::PACKET* TH_PACKET::_internal_add_packet() {
  return packet_.Add();
}
inline ::TH_SERVER::PACKET* TH_PACKET::add_packet() {
  ::TH_SERVER::PACKET* _add = _internal_add_packet();
  // @@protoc_insertion_point(field_add:TH_SERVER.TH_PACKET.packet)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TH_SERVER::PACKET >&
TH_PACKET::packet() const {
  // @@protoc_insertion_point(field_list:TH_SERVER.TH_PACKET.packet)
  return packet_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace TH_SERVER

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::TH_SERVER::PACKET_TYPE> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::TH_SERVER::PACKET_TYPE>() {
  return ::TH_SERVER::PACKET_TYPE_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Packet_2eproto
