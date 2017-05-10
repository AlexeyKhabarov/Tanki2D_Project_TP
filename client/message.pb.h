// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef PROTOBUF_message_2eproto__INCLUDED
#define PROTOBUF_message_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
class Player;
class PlayerDefaultTypeInternal;
extern PlayerDefaultTypeInternal _Player_default_instance_;

namespace protobuf_message_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_message_2eproto

enum Player_Dir {
  Player_Dir_UP = 0,
  Player_Dir_DOWN = 1,
  Player_Dir_LEFT = 2,
  Player_Dir_RIGHT = 3
};
bool Player_Dir_IsValid(int value);
const Player_Dir Player_Dir_Dir_MIN = Player_Dir_UP;
const Player_Dir Player_Dir_Dir_MAX = Player_Dir_RIGHT;
const int Player_Dir_Dir_ARRAYSIZE = Player_Dir_Dir_MAX + 1;

const ::google::protobuf::EnumDescriptor* Player_Dir_descriptor();
inline const ::std::string& Player_Dir_Name(Player_Dir value) {
  return ::google::protobuf::internal::NameOfEnum(
    Player_Dir_descriptor(), value);
}
inline bool Player_Dir_Parse(
    const ::std::string& name, Player_Dir* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Player_Dir>(
    Player_Dir_descriptor(), name, value);
}
// ===================================================================

class Player : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Player) */ {
 public:
  Player();
  virtual ~Player();

  Player(const Player& from);

  inline Player& operator=(const Player& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Player& default_instance();

  static inline const Player* internal_default_instance() {
    return reinterpret_cast<const Player*>(
               &_Player_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Player* other);

  // implements Message ----------------------------------------------

  inline Player* New() const PROTOBUF_FINAL { return New(NULL); }

  Player* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Player& from);
  void MergeFrom(const Player& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Player* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef Player_Dir Dir;
  static const Dir UP =
    Player_Dir_UP;
  static const Dir DOWN =
    Player_Dir_DOWN;
  static const Dir LEFT =
    Player_Dir_LEFT;
  static const Dir RIGHT =
    Player_Dir_RIGHT;
  static inline bool Dir_IsValid(int value) {
    return Player_Dir_IsValid(value);
  }
  static const Dir Dir_MIN =
    Player_Dir_Dir_MIN;
  static const Dir Dir_MAX =
    Player_Dir_Dir_MAX;
  static const int Dir_ARRAYSIZE =
    Player_Dir_Dir_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Dir_descriptor() {
    return Player_Dir_descriptor();
  }
  static inline const ::std::string& Dir_Name(Dir value) {
    return Player_Dir_Name(value);
  }
  static inline bool Dir_Parse(const ::std::string& name,
      Dir* value) {
    return Player_Dir_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional string name = 1;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional int32 hp = 2;
  bool has_hp() const;
  void clear_hp();
  static const int kHpFieldNumber = 2;
  ::google::protobuf::int32 hp() const;
  void set_hp(::google::protobuf::int32 value);

  // optional float x = 3;
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 3;
  float x() const;
  void set_x(float value);

  // optional float y = 4;
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 4;
  float y() const;
  void set_y(float value);

  // optional int32 state = 5;
  bool has_state() const;
  void clear_state();
  static const int kStateFieldNumber = 5;
  ::google::protobuf::int32 state() const;
  void set_state(::google::protobuf::int32 value);

  // optional .Player.Dir dir = 6;
  bool has_dir() const;
  void clear_dir();
  static const int kDirFieldNumber = 6;
  ::Player_Dir dir() const;
  void set_dir(::Player_Dir value);

  // optional float t1 = 7;
  bool has_t1() const;
  void clear_t1();
  static const int kT1FieldNumber = 7;
  float t1() const;
  void set_t1(float value);

  // optional float t2 = 8;
  bool has_t2() const;
  void clear_t2();
  static const int kT2FieldNumber = 8;
  float t2() const;
  void set_t2(float value);

  // optional float size_x = 9;
  bool has_size_x() const;
  void clear_size_x();
  static const int kSizeXFieldNumber = 9;
  float size_x() const;
  void set_size_x(float value);

  // optional float size_y = 10;
  bool has_size_y() const;
  void clear_size_y();
  static const int kSizeYFieldNumber = 10;
  float size_y() const;
  void set_size_y(float value);

  // optional float bullet_x = 11;
  bool has_bullet_x() const;
  void clear_bullet_x();
  static const int kBulletXFieldNumber = 11;
  float bullet_x() const;
  void set_bullet_x(float value);

  // optional float bullet_y = 12;
  bool has_bullet_y() const;
  void clear_bullet_y();
  static const int kBulletYFieldNumber = 12;
  float bullet_y() const;
  void set_bullet_y(float value);

  // optional bool bullet_life = 13;
  bool has_bullet_life() const;
  void clear_bullet_life();
  static const int kBulletLifeFieldNumber = 13;
  bool bullet_life() const;
  void set_bullet_life(bool value);

  // optional int32 bullet_dir = 14;
  bool has_bullet_dir() const;
  void clear_bullet_dir();
  static const int kBulletDirFieldNumber = 14;
  ::google::protobuf::int32 bullet_dir() const;
  void set_bullet_dir(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Player)
 private:
  void set_has_name();
  void clear_has_name();
  void set_has_hp();
  void clear_has_hp();
  void set_has_x();
  void clear_has_x();
  void set_has_y();
  void clear_has_y();
  void set_has_state();
  void clear_has_state();
  void set_has_dir();
  void clear_has_dir();
  void set_has_t1();
  void clear_has_t1();
  void set_has_t2();
  void clear_has_t2();
  void set_has_size_x();
  void clear_has_size_x();
  void set_has_size_y();
  void clear_has_size_y();
  void set_has_bullet_x();
  void clear_has_bullet_x();
  void set_has_bullet_y();
  void clear_has_bullet_y();
  void set_has_bullet_life();
  void clear_has_bullet_life();
  void set_has_bullet_dir();
  void clear_has_bullet_dir();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 hp_;
  float x_;
  float y_;
  ::google::protobuf::int32 state_;
  int dir_;
  float t1_;
  float t2_;
  float size_x_;
  float size_y_;
  float bullet_x_;
  float bullet_y_;
  bool bullet_life_;
  ::google::protobuf::int32 bullet_dir_;
  friend struct protobuf_message_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Player

// optional string name = 1;
inline bool Player::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Player::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Player::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Player::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Player::name() const {
  // @@protoc_insertion_point(field_get:Player.name)
  return name_.GetNoArena();
}
inline void Player::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Player.name)
}
#if LANG_CXX11
inline void Player::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Player.name)
}
#endif
inline void Player::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Player.name)
}
inline void Player::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Player.name)
}
inline ::std::string* Player::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:Player.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Player::release_name() {
  // @@protoc_insertion_point(field_release:Player.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Player::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Player.name)
}

// optional int32 hp = 2;
inline bool Player::has_hp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Player::set_has_hp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Player::clear_has_hp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Player::clear_hp() {
  hp_ = 0;
  clear_has_hp();
}
inline ::google::protobuf::int32 Player::hp() const {
  // @@protoc_insertion_point(field_get:Player.hp)
  return hp_;
}
inline void Player::set_hp(::google::protobuf::int32 value) {
  set_has_hp();
  hp_ = value;
  // @@protoc_insertion_point(field_set:Player.hp)
}

// optional float x = 3;
inline bool Player::has_x() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Player::set_has_x() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Player::clear_has_x() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Player::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Player::x() const {
  // @@protoc_insertion_point(field_get:Player.x)
  return x_;
}
inline void Player::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:Player.x)
}

// optional float y = 4;
inline bool Player::has_y() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Player::set_has_y() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Player::clear_has_y() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Player::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Player::y() const {
  // @@protoc_insertion_point(field_get:Player.y)
  return y_;
}
inline void Player::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:Player.y)
}

// optional int32 state = 5;
inline bool Player::has_state() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Player::set_has_state() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Player::clear_has_state() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Player::clear_state() {
  state_ = 0;
  clear_has_state();
}
inline ::google::protobuf::int32 Player::state() const {
  // @@protoc_insertion_point(field_get:Player.state)
  return state_;
}
inline void Player::set_state(::google::protobuf::int32 value) {
  set_has_state();
  state_ = value;
  // @@protoc_insertion_point(field_set:Player.state)
}

// optional .Player.Dir dir = 6;
inline bool Player::has_dir() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Player::set_has_dir() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Player::clear_has_dir() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Player::clear_dir() {
  dir_ = 0;
  clear_has_dir();
}
inline ::Player_Dir Player::dir() const {
  // @@protoc_insertion_point(field_get:Player.dir)
  return static_cast< ::Player_Dir >(dir_);
}
inline void Player::set_dir(::Player_Dir value) {
  assert(::Player_Dir_IsValid(value));
  set_has_dir();
  dir_ = value;
  // @@protoc_insertion_point(field_set:Player.dir)
}

// optional float t1 = 7;
inline bool Player::has_t1() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Player::set_has_t1() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Player::clear_has_t1() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Player::clear_t1() {
  t1_ = 0;
  clear_has_t1();
}
inline float Player::t1() const {
  // @@protoc_insertion_point(field_get:Player.t1)
  return t1_;
}
inline void Player::set_t1(float value) {
  set_has_t1();
  t1_ = value;
  // @@protoc_insertion_point(field_set:Player.t1)
}

// optional float t2 = 8;
inline bool Player::has_t2() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Player::set_has_t2() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Player::clear_has_t2() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Player::clear_t2() {
  t2_ = 0;
  clear_has_t2();
}
inline float Player::t2() const {
  // @@protoc_insertion_point(field_get:Player.t2)
  return t2_;
}
inline void Player::set_t2(float value) {
  set_has_t2();
  t2_ = value;
  // @@protoc_insertion_point(field_set:Player.t2)
}

// optional float size_x = 9;
inline bool Player::has_size_x() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Player::set_has_size_x() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Player::clear_has_size_x() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Player::clear_size_x() {
  size_x_ = 0;
  clear_has_size_x();
}
inline float Player::size_x() const {
  // @@protoc_insertion_point(field_get:Player.size_x)
  return size_x_;
}
inline void Player::set_size_x(float value) {
  set_has_size_x();
  size_x_ = value;
  // @@protoc_insertion_point(field_set:Player.size_x)
}

// optional float size_y = 10;
inline bool Player::has_size_y() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void Player::set_has_size_y() {
  _has_bits_[0] |= 0x00000200u;
}
inline void Player::clear_has_size_y() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void Player::clear_size_y() {
  size_y_ = 0;
  clear_has_size_y();
}
inline float Player::size_y() const {
  // @@protoc_insertion_point(field_get:Player.size_y)
  return size_y_;
}
inline void Player::set_size_y(float value) {
  set_has_size_y();
  size_y_ = value;
  // @@protoc_insertion_point(field_set:Player.size_y)
}

// optional float bullet_x = 11;
inline bool Player::has_bullet_x() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void Player::set_has_bullet_x() {
  _has_bits_[0] |= 0x00000400u;
}
inline void Player::clear_has_bullet_x() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void Player::clear_bullet_x() {
  bullet_x_ = 0;
  clear_has_bullet_x();
}
inline float Player::bullet_x() const {
  // @@protoc_insertion_point(field_get:Player.bullet_x)
  return bullet_x_;
}
inline void Player::set_bullet_x(float value) {
  set_has_bullet_x();
  bullet_x_ = value;
  // @@protoc_insertion_point(field_set:Player.bullet_x)
}

// optional float bullet_y = 12;
inline bool Player::has_bullet_y() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void Player::set_has_bullet_y() {
  _has_bits_[0] |= 0x00000800u;
}
inline void Player::clear_has_bullet_y() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void Player::clear_bullet_y() {
  bullet_y_ = 0;
  clear_has_bullet_y();
}
inline float Player::bullet_y() const {
  // @@protoc_insertion_point(field_get:Player.bullet_y)
  return bullet_y_;
}
inline void Player::set_bullet_y(float value) {
  set_has_bullet_y();
  bullet_y_ = value;
  // @@protoc_insertion_point(field_set:Player.bullet_y)
}

// optional bool bullet_life = 13;
inline bool Player::has_bullet_life() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void Player::set_has_bullet_life() {
  _has_bits_[0] |= 0x00001000u;
}
inline void Player::clear_has_bullet_life() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void Player::clear_bullet_life() {
  bullet_life_ = false;
  clear_has_bullet_life();
}
inline bool Player::bullet_life() const {
  // @@protoc_insertion_point(field_get:Player.bullet_life)
  return bullet_life_;
}
inline void Player::set_bullet_life(bool value) {
  set_has_bullet_life();
  bullet_life_ = value;
  // @@protoc_insertion_point(field_set:Player.bullet_life)
}

// optional int32 bullet_dir = 14;
inline bool Player::has_bullet_dir() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void Player::set_has_bullet_dir() {
  _has_bits_[0] |= 0x00002000u;
}
inline void Player::clear_has_bullet_dir() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void Player::clear_bullet_dir() {
  bullet_dir_ = 0;
  clear_has_bullet_dir();
}
inline ::google::protobuf::int32 Player::bullet_dir() const {
  // @@protoc_insertion_point(field_get:Player.bullet_dir)
  return bullet_dir_;
}
inline void Player::set_bullet_dir(::google::protobuf::int32 value) {
  set_has_bullet_dir();
  bullet_dir_ = value;
  // @@protoc_insertion_point(field_set:Player.bullet_dir)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Player_Dir> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Player_Dir>() {
  return ::Player_Dir_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_2eproto__INCLUDED
