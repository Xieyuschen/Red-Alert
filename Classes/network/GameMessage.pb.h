// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameMessage.proto

#ifndef PROTOBUF_GameMessage_2eproto__INCLUDED
#define PROTOBUF_GameMessage_2eproto__INCLUDED

#include <string>
#include"cocos2d.h"
#include<iostream>
#include<vector>
USING_NS_CC;
using namespace std;

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

#pragma comment (lib, "libprotobuf-lited.lib")
#pragma comment (lib, "libprotobufd.lib")

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
class GameMessage;
class GameMessageDefaultTypeInternal;
extern GameMessageDefaultTypeInternal _GameMessage_default_instance_;
class GameMessageSet;
class GameMessageSetDefaultTypeInternal;
extern GameMessageSetDefaultTypeInternal _GameMessageSet_default_instance_;
class Path;
class PathDefaultTypeInternal;
extern PathDefaultTypeInternal _Path_default_instance_;
class Vec;
class VecDefaultTypeInternal;
extern VecDefaultTypeInternal _Vec_default_instance_;

namespace protobuf_GameMessage_2eproto {
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
}  // namespace protobuf_GameMessage_2eproto

enum GameMessage_CmdCode {
  GameMessage_CmdCode_EMP = 0,
  GameMessage_CmdCode_CRTB = 1,
  GameMessage_CmdCode_CRTS = 2,
  GameMessage_CmdCode_MOV = 3,
  GameMessage_CmdCode_GameMessage_CmdCode_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  GameMessage_CmdCode_GameMessage_CmdCode_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool GameMessage_CmdCode_IsValid(int value);
const GameMessage_CmdCode GameMessage_CmdCode_CmdCode_MIN = GameMessage_CmdCode_EMP;
const GameMessage_CmdCode GameMessage_CmdCode_CmdCode_MAX = GameMessage_CmdCode_MOV;
const int GameMessage_CmdCode_CmdCode_ARRAYSIZE = GameMessage_CmdCode_CmdCode_MAX + 1;

const ::google::protobuf::EnumDescriptor* GameMessage_CmdCode_descriptor();
inline const ::std::string& GameMessage_CmdCode_Name(GameMessage_CmdCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    GameMessage_CmdCode_descriptor(), value);
}
inline bool GameMessage_CmdCode_Parse(
    const ::std::string& name, GameMessage_CmdCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<GameMessage_CmdCode>(
    GameMessage_CmdCode_descriptor(), name, value);
}
// ===================================================================

class GameMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GameMessage) */ {
 public:
  GameMessage();
  virtual ~GameMessage();

  GameMessage(const GameMessage& from);

  inline GameMessage& operator=(const GameMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GameMessage& default_instance();

  static inline const GameMessage* internal_default_instance() {
    return reinterpret_cast<const GameMessage*>(
               &_GameMessage_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(GameMessage* other);

  // implements Message ----------------------------------------------

  inline GameMessage* New() const PROTOBUF_FINAL { return New(NULL); }

  GameMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GameMessage& from);
  void MergeFrom(const GameMessage& from);
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
  void InternalSwap(GameMessage* other);
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

  typedef GameMessage_CmdCode CmdCode;
  static const CmdCode EMP =
    GameMessage_CmdCode_EMP;
  static const CmdCode CRTB =
    GameMessage_CmdCode_CRTB;
  static const CmdCode CRTS =
    GameMessage_CmdCode_CRTS;
  static const CmdCode MOV =
    GameMessage_CmdCode_MOV;
  static inline bool CmdCode_IsValid(int value) {
    return GameMessage_CmdCode_IsValid(value);
  }
  static const CmdCode CmdCode_MIN =
    GameMessage_CmdCode_CmdCode_MIN;
  static const CmdCode CmdCode_MAX =
    GameMessage_CmdCode_CmdCode_MAX;
  static const int CmdCode_ARRAYSIZE =
    GameMessage_CmdCode_CmdCode_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  CmdCode_descriptor() {
    return GameMessage_CmdCode_descriptor();
  }
  static inline const ::std::string& CmdCode_Name(CmdCode value) {
    return GameMessage_CmdCode_Name(value);
  }
  static inline bool CmdCode_Parse(const ::std::string& name,
      CmdCode* value) {
    return GameMessage_CmdCode_Parse(name, value);
  }

  // accessors -------------------------------------------------------
  void GameMessage::genGameMessage(CmdCode _cmd_code, int player_id, int id, int btype , int stype, const vector<Vec2> &_movepath);

  // .Path movepath = 6;
  bool has_movepath() const;
  void clear_movepath();
  static const int kMovepathFieldNumber = 6;
  const ::Path& movepath() const;
  ::Path* mutable_movepath();
  ::Path* release_movepath();
  void set_allocated_movepath(::Path* movepath);

  // .GameMessage.CmdCode cmd_code = 1;
  void clear_cmd_code();
  static const int kCmdCodeFieldNumber = 1;
  ::GameMessage_CmdCode cmd_code() const;
  void set_cmd_code(::GameMessage_CmdCode value);

  // int32 playerid = 2;
  void clear_playerid();
  static const int kPlayeridFieldNumber = 2;
  ::google::protobuf::int32 playerid() const;
  void set_playerid(::google::protobuf::int32 value);

  // int32 id = 3;
  void clear_id();
  static const int kIdFieldNumber = 3;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // int32 btype = 4;
  void clear_btype();
  static const int kBtypeFieldNumber = 4;
  ::google::protobuf::int32 btype() const;
  void set_btype(::google::protobuf::int32 value);

  // int32 stype = 5;
  void clear_stype();
  static const int kStypeFieldNumber = 5;
  ::google::protobuf::int32 stype() const;
  void set_stype(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:GameMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::Path* movepath_;
  int cmd_code_;
  ::google::protobuf::int32 playerid_;
  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 btype_;
  ::google::protobuf::int32 stype_;
  mutable int _cached_size_;
  friend struct protobuf_GameMessage_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Vec : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Vec) */ {
 public:
  Vec();
  virtual ~Vec();

  Vec(const Vec& from);

  inline Vec& operator=(const Vec& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Vec& default_instance();

  static inline const Vec* internal_default_instance() {
    return reinterpret_cast<const Vec*>(
               &_Vec_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(Vec* other);

  // implements Message ----------------------------------------------

  inline Vec* New() const PROTOBUF_FINAL { return New(NULL); }

  Vec* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Vec& from);
  void MergeFrom(const Vec& from);
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
  void InternalSwap(Vec* other);
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

  // accessors -------------------------------------------------------

  // float x = 1;
  void clear_x();
  static const int kXFieldNumber = 1;
  float x() const;
  void set_x(float value);

  // float y = 2;
  void clear_y();
  static const int kYFieldNumber = 2;
  float y() const;
  void set_y(float value);

  // @@protoc_insertion_point(class_scope:Vec)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  float x_;
  float y_;
  mutable int _cached_size_;
  friend struct protobuf_GameMessage_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Path : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Path) */ {
 public:
  Path();
  virtual ~Path();

  Path(const Path& from);

  inline Path& operator=(const Path& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Path& default_instance();

  static inline const Path* internal_default_instance() {
    return reinterpret_cast<const Path*>(
               &_Path_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(Path* other);

  // implements Message ----------------------------------------------

  inline Path* New() const PROTOBUF_FINAL { return New(NULL); }

  Path* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Path& from);
  void MergeFrom(const Path& from);
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
  void InternalSwap(Path* other);
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

  // accessors -------------------------------------------------------

  // repeated .Vec vec = 1;
  int vec_size() const;
  void clear_vec();
  static const int kVecFieldNumber = 1;
  const ::Vec& vec(int index) const;
  ::Vec* mutable_vec(int index);
  ::Vec* add_vec();
  ::google::protobuf::RepeatedPtrField< ::Vec >*
      mutable_vec();
  const ::google::protobuf::RepeatedPtrField< ::Vec >&
      vec() const;

  // @@protoc_insertion_point(class_scope:Path)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::Vec > vec_;
  mutable int _cached_size_;
  friend struct protobuf_GameMessage_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class GameMessageSet : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GameMessageSet) */ {
 public:
  GameMessageSet();
  virtual ~GameMessageSet();

  GameMessageSet(const GameMessageSet& from);

  inline GameMessageSet& operator=(const GameMessageSet& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GameMessageSet& default_instance();

  static inline const GameMessageSet* internal_default_instance() {
    return reinterpret_cast<const GameMessageSet*>(
               &_GameMessageSet_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(GameMessageSet* other);

  // implements Message ----------------------------------------------

  inline GameMessageSet* New() const PROTOBUF_FINAL { return New(NULL); }

  GameMessageSet* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GameMessageSet& from);
  void MergeFrom(const GameMessageSet& from);
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
  void InternalSwap(GameMessageSet* other);
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

  // accessors -------------------------------------------------------

  // repeated .GameMessage game_message = 1;
  int game_message_size() const;
  void clear_game_message();
  static const int kGameMessageFieldNumber = 1;
  const ::GameMessage& game_message(int index) const;
  ::GameMessage* mutable_game_message(int index);
  ::GameMessage* add_game_message();
  ::google::protobuf::RepeatedPtrField< ::GameMessage >*
      mutable_game_message();
  const ::google::protobuf::RepeatedPtrField< ::GameMessage >&
      game_message() const;

  // @@protoc_insertion_point(class_scope:GameMessageSet)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::GameMessage > game_message_;
  mutable int _cached_size_;
  friend struct protobuf_GameMessage_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// GameMessage

// .GameMessage.CmdCode cmd_code = 1;
inline void GameMessage::clear_cmd_code() {
  cmd_code_ = 0;
}
inline ::GameMessage_CmdCode GameMessage::cmd_code() const {
  // @@protoc_insertion_point(field_get:GameMessage.cmd_code)
  return static_cast< ::GameMessage_CmdCode >(cmd_code_);
}
inline void GameMessage::set_cmd_code(::GameMessage_CmdCode value) {
  
  cmd_code_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.cmd_code)
}

// int32 playerid = 2;
inline void GameMessage::clear_playerid() {
  playerid_ = 0;
}
inline ::google::protobuf::int32 GameMessage::playerid() const {
  // @@protoc_insertion_point(field_get:GameMessage.playerid)
  return playerid_;
}
inline void GameMessage::set_playerid(::google::protobuf::int32 value) {
  
  playerid_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.playerid)
}

// int32 id = 3;
inline void GameMessage::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 GameMessage::id() const {
  // @@protoc_insertion_point(field_get:GameMessage.id)
  return id_;
}
inline void GameMessage::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.id)
}

// int32 btype = 4;
inline void GameMessage::clear_btype() {
  btype_ = 0;
}
inline ::google::protobuf::int32 GameMessage::btype() const {
  // @@protoc_insertion_point(field_get:GameMessage.btype)
  return btype_;
}
inline void GameMessage::set_btype(::google::protobuf::int32 value) {
  
  btype_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.btype)
}

// int32 stype = 5;
inline void GameMessage::clear_stype() {
  stype_ = 0;
}
inline ::google::protobuf::int32 GameMessage::stype() const {
  // @@protoc_insertion_point(field_get:GameMessage.stype)
  return stype_;
}
inline void GameMessage::set_stype(::google::protobuf::int32 value) {
  
  stype_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.stype)
}

// .Path movepath = 6;
inline bool GameMessage::has_movepath() const {
  return this != internal_default_instance() && movepath_ != NULL;
}
inline void GameMessage::clear_movepath() {
  if (GetArenaNoVirtual() == NULL && movepath_ != NULL) delete movepath_;
  movepath_ = NULL;
}
inline const ::Path& GameMessage::movepath() const {
  // @@protoc_insertion_point(field_get:GameMessage.movepath)
  return movepath_ != NULL ? *movepath_
                         : *::Path::internal_default_instance();
}
inline ::Path* GameMessage::mutable_movepath() {
  
  if (movepath_ == NULL) {
    movepath_ = new ::Path;
  }
  // @@protoc_insertion_point(field_mutable:GameMessage.movepath)
  return movepath_;
}
inline ::Path* GameMessage::release_movepath() {
  // @@protoc_insertion_point(field_release:GameMessage.movepath)
  
  ::Path* temp = movepath_;
  movepath_ = NULL;
  return temp;
}
inline void GameMessage::set_allocated_movepath(::Path* movepath) {
  delete movepath_;
  movepath_ = movepath;
  if (movepath) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:GameMessage.movepath)
}

// -------------------------------------------------------------------

// Vec

// float x = 1;
inline void Vec::clear_x() {
  x_ = 0;
}
inline float Vec::x() const {
  // @@protoc_insertion_point(field_get:Vec.x)
  return x_;
}
inline void Vec::set_x(float value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:Vec.x)
}

// float y = 2;
inline void Vec::clear_y() {
  y_ = 0;
}
inline float Vec::y() const {
  // @@protoc_insertion_point(field_get:Vec.y)
  return y_;
}
inline void Vec::set_y(float value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:Vec.y)
}

// -------------------------------------------------------------------

// Path

// repeated .Vec vec = 1;
inline int Path::vec_size() const {
  return vec_.size();
}
inline void Path::clear_vec() {
  vec_.Clear();
}
inline const ::Vec& Path::vec(int index) const {
  // @@protoc_insertion_point(field_get:Path.vec)
  return vec_.Get(index);
}
inline ::Vec* Path::mutable_vec(int index) {
  // @@protoc_insertion_point(field_mutable:Path.vec)
  return vec_.Mutable(index);
}
inline ::Vec* Path::add_vec() {
  // @@protoc_insertion_point(field_add:Path.vec)
  return vec_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Vec >*
Path::mutable_vec() {
  // @@protoc_insertion_point(field_mutable_list:Path.vec)
  return &vec_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Vec >&
Path::vec() const {
  // @@protoc_insertion_point(field_list:Path.vec)
  return vec_;
}

// -------------------------------------------------------------------

// GameMessageSet

// repeated .GameMessage game_message = 1;
inline int GameMessageSet::game_message_size() const {
  return game_message_.size();
}
inline void GameMessageSet::clear_game_message() {
  game_message_.Clear();
}
inline const ::GameMessage& GameMessageSet::game_message(int index) const {
  // @@protoc_insertion_point(field_get:GameMessageSet.game_message)
  return game_message_.Get(index);
}
inline ::GameMessage* GameMessageSet::mutable_game_message(int index) {
  // @@protoc_insertion_point(field_mutable:GameMessageSet.game_message)
  return game_message_.Mutable(index);
}
inline ::GameMessage* GameMessageSet::add_game_message() {
  // @@protoc_insertion_point(field_add:GameMessageSet.game_message)
  return game_message_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::GameMessage >*
GameMessageSet::mutable_game_message() {
  // @@protoc_insertion_point(field_mutable_list:GameMessageSet.game_message)
  return &game_message_;
}
inline const ::google::protobuf::RepeatedPtrField< ::GameMessage >&
GameMessageSet::game_message() const {
  // @@protoc_insertion_point(field_list:GameMessageSet.game_message)
  return game_message_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::GameMessage_CmdCode> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::GameMessage_CmdCode>() {
  return ::GameMessage_CmdCode_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_GameMessage_2eproto__INCLUDED
