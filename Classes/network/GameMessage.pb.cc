// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameMessage.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "GameMessage.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
class GameMessageDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<GameMessage> {
} _GameMessage_default_instance_;
class GameMessageSetDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<GameMessageSet> {
} _GameMessageSet_default_instance_;
void GameMessage::genGameMessage(CmdCode _cmd_code, int player_id, int id, int btype,int stype)
{
	set_cmd_code(_cmd_code);
	set_playerid(player_id);
	set_id(id);
	set_btype(btype);
	set_stype(stype);

}
namespace protobuf_GameMessage_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[2];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] = {
  { NULL, NULL, 0, -1, -1, false },
  { NULL, NULL, 0, -1, -1, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessage, cmd_code_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessage, playerid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessage, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessage, btype_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessage, stype_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessageSet, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameMessageSet, game_message_),
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, -1, sizeof(GameMessage)},
  { 10, -1, sizeof(GameMessageSet)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_GameMessage_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_GameMessageSet_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "GameMessage.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

}  // namespace

void TableStruct::Shutdown() {
  _GameMessage_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
  _GameMessageSet_default_instance_.Shutdown();
  delete file_level_metadata[1].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _GameMessage_default_instance_.DefaultConstruct();
  _GameMessageSet_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\021GameMessage.proto\"\231\001\n\013GameMessage\022&\n\010c"
      "md_code\030\001 \001(\0162\024.GameMessage.CmdCode\022\020\n\010p"
      "layerid\030\002 \001(\005\022\n\n\002id\030\003 \001(\005\022\r\n\005btype\030\004 \001(\005"
      "\022\r\n\005stype\030\005 \001(\005\"&\n\007CmdCode\022\007\n\003EMP\020\000\022\010\n\004C"
      "RTB\020\001\022\010\n\004CRTS\020\002\"4\n\016GameMessageSet\022\"\n\014gam"
      "e_message\030\001 \003(\0132\014.GameMessageb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 237);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "GameMessage.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_GameMessage_2eproto

const ::google::protobuf::EnumDescriptor* GameMessage_CmdCode_descriptor() {
  protobuf_GameMessage_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameMessage_2eproto::file_level_enum_descriptors[0];
}
bool GameMessage_CmdCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const GameMessage_CmdCode GameMessage::EMP;
const GameMessage_CmdCode GameMessage::CRTB;
const GameMessage_CmdCode GameMessage::CRTS;
const GameMessage_CmdCode GameMessage::CmdCode_MIN;
const GameMessage_CmdCode GameMessage::CmdCode_MAX;
const int GameMessage::CmdCode_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GameMessage::kCmdCodeFieldNumber;
const int GameMessage::kPlayeridFieldNumber;
const int GameMessage::kIdFieldNumber;
const int GameMessage::kBtypeFieldNumber;
const int GameMessage::kStypeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GameMessage::GameMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_GameMessage_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:GameMessage)
}
GameMessage::GameMessage(const GameMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&cmd_code_, &from.cmd_code_,
    reinterpret_cast<char*>(&stype_) -
    reinterpret_cast<char*>(&cmd_code_) + sizeof(stype_));
  // @@protoc_insertion_point(copy_constructor:GameMessage)
}

void GameMessage::SharedCtor() {
  ::memset(&cmd_code_, 0, reinterpret_cast<char*>(&stype_) -
    reinterpret_cast<char*>(&cmd_code_) + sizeof(stype_));
  _cached_size_ = 0;
}

GameMessage::~GameMessage() {
  // @@protoc_insertion_point(destructor:GameMessage)
  SharedDtor();
}

void GameMessage::SharedDtor() {
}

void GameMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameMessage::descriptor() {
  protobuf_GameMessage_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameMessage_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GameMessage& GameMessage::default_instance() {
  protobuf_GameMessage_2eproto::InitDefaults();
  return *internal_default_instance();
}

GameMessage* GameMessage::New(::google::protobuf::Arena* arena) const {
  GameMessage* n = new GameMessage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GameMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:GameMessage)
  ::memset(&cmd_code_, 0, reinterpret_cast<char*>(&stype_) -
    reinterpret_cast<char*>(&cmd_code_) + sizeof(stype_));
}

bool GameMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GameMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .GameMessage.CmdCode cmd_code = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_cmd_code(static_cast< ::GameMessage_CmdCode >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 playerid = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &playerid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 id = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 btype = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &btype_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 stype = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &stype_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:GameMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GameMessage)
  return false;
#undef DO_
}

void GameMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GameMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .GameMessage.CmdCode cmd_code = 1;
  if (this->cmd_code() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->cmd_code(), output);
  }

  // int32 playerid = 2;
  if (this->playerid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->playerid(), output);
  }

  // int32 id = 3;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->id(), output);
  }

  // int32 btype = 4;
  if (this->btype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->btype(), output);
  }

  // int32 stype = 5;
  if (this->stype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->stype(), output);
  }

  // @@protoc_insertion_point(serialize_end:GameMessage)
}

::google::protobuf::uint8* GameMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:GameMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .GameMessage.CmdCode cmd_code = 1;
  if (this->cmd_code() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->cmd_code(), target);
  }

  // int32 playerid = 2;
  if (this->playerid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->playerid(), target);
  }

  // int32 id = 3;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->id(), target);
  }

  // int32 btype = 4;
  if (this->btype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->btype(), target);
  }

  // int32 stype = 5;
  if (this->stype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->stype(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:GameMessage)
  return target;
}

size_t GameMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GameMessage)
  size_t total_size = 0;

  // .GameMessage.CmdCode cmd_code = 1;
  if (this->cmd_code() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->cmd_code());
  }

  // int32 playerid = 2;
  if (this->playerid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->playerid());
  }

  // int32 id = 3;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  // int32 btype = 4;
  if (this->btype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->btype());
  }

  // int32 stype = 5;
  if (this->stype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->stype());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GameMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const GameMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GameMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GameMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GameMessage)
    MergeFrom(*source);
  }
}

void GameMessage::MergeFrom(const GameMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GameMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.cmd_code() != 0) {
    set_cmd_code(from.cmd_code());
  }
  if (from.playerid() != 0) {
    set_playerid(from.playerid());
  }
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.btype() != 0) {
    set_btype(from.btype());
  }
  if (from.stype() != 0) {
    set_stype(from.stype());
  }
}

void GameMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GameMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameMessage::CopyFrom(const GameMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GameMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameMessage::IsInitialized() const {
  return true;
}

void GameMessage::Swap(GameMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GameMessage::InternalSwap(GameMessage* other) {
  std::swap(cmd_code_, other->cmd_code_);
  std::swap(playerid_, other->playerid_);
  std::swap(id_, other->id_);
  std::swap(btype_, other->btype_);
  std::swap(stype_, other->stype_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GameMessage::GetMetadata() const {
  protobuf_GameMessage_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameMessage_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GameMessage

// .GameMessage.CmdCode cmd_code = 1;
void GameMessage::clear_cmd_code() {
  cmd_code_ = 0;
}
::GameMessage_CmdCode GameMessage::cmd_code() const {
  // @@protoc_insertion_point(field_get:GameMessage.cmd_code)
  return static_cast< ::GameMessage_CmdCode >(cmd_code_);
}
void GameMessage::set_cmd_code(::GameMessage_CmdCode value) {
  
  cmd_code_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.cmd_code)
}

// int32 playerid = 2;
void GameMessage::clear_playerid() {
  playerid_ = 0;
}
::google::protobuf::int32 GameMessage::playerid() const {
  // @@protoc_insertion_point(field_get:GameMessage.playerid)
  return playerid_;
}
void GameMessage::set_playerid(::google::protobuf::int32 value) {
  
  playerid_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.playerid)
}

// int32 id = 3;
void GameMessage::clear_id() {
  id_ = 0;
}
::google::protobuf::int32 GameMessage::id() const {
  // @@protoc_insertion_point(field_get:GameMessage.id)
  return id_;
}
void GameMessage::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.id)
}

// int32 btype = 4;
void GameMessage::clear_btype() {
  btype_ = 0;
}
::google::protobuf::int32 GameMessage::btype() const {
  // @@protoc_insertion_point(field_get:GameMessage.btype)
  return btype_;
}
void GameMessage::set_btype(::google::protobuf::int32 value) {
  
  btype_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.btype)
}

// int32 stype = 5;
void GameMessage::clear_stype() {
  stype_ = 0;
}
::google::protobuf::int32 GameMessage::stype() const {
  // @@protoc_insertion_point(field_get:GameMessage.stype)
  return stype_;
}
void GameMessage::set_stype(::google::protobuf::int32 value) {
  
  stype_ = value;
  // @@protoc_insertion_point(field_set:GameMessage.stype)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GameMessageSet::kGameMessageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GameMessageSet::GameMessageSet()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_GameMessage_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:GameMessageSet)
}
GameMessageSet::GameMessageSet(const GameMessageSet& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      game_message_(from.game_message_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:GameMessageSet)
}

void GameMessageSet::SharedCtor() {
  _cached_size_ = 0;
}

GameMessageSet::~GameMessageSet() {
  // @@protoc_insertion_point(destructor:GameMessageSet)
  SharedDtor();
}

void GameMessageSet::SharedDtor() {
}

void GameMessageSet::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameMessageSet::descriptor() {
  protobuf_GameMessage_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameMessage_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GameMessageSet& GameMessageSet::default_instance() {
  protobuf_GameMessage_2eproto::InitDefaults();
  return *internal_default_instance();
}

GameMessageSet* GameMessageSet::New(::google::protobuf::Arena* arena) const {
  GameMessageSet* n = new GameMessageSet;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GameMessageSet::Clear() {
// @@protoc_insertion_point(message_clear_start:GameMessageSet)
  game_message_.Clear();
}

bool GameMessageSet::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GameMessageSet)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .GameMessage game_message = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_game_message()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:GameMessageSet)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GameMessageSet)
  return false;
#undef DO_
}

void GameMessageSet::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GameMessageSet)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .GameMessage game_message = 1;
  for (unsigned int i = 0, n = this->game_message_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->game_message(i), output);
  }

  // @@protoc_insertion_point(serialize_end:GameMessageSet)
}

::google::protobuf::uint8* GameMessageSet::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:GameMessageSet)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .GameMessage game_message = 1;
  for (unsigned int i = 0, n = this->game_message_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->game_message(i), deterministic, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:GameMessageSet)
  return target;
}

size_t GameMessageSet::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GameMessageSet)
  size_t total_size = 0;

  // repeated .GameMessage game_message = 1;
  {
    unsigned int count = this->game_message_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->game_message(i));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameMessageSet::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GameMessageSet)
  GOOGLE_DCHECK_NE(&from, this);
  const GameMessageSet* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GameMessageSet>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GameMessageSet)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GameMessageSet)
    MergeFrom(*source);
  }
}

void GameMessageSet::MergeFrom(const GameMessageSet& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GameMessageSet)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  game_message_.MergeFrom(from.game_message_);
}

void GameMessageSet::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GameMessageSet)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameMessageSet::CopyFrom(const GameMessageSet& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GameMessageSet)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameMessageSet::IsInitialized() const {
  return true;
}

void GameMessageSet::Swap(GameMessageSet* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GameMessageSet::InternalSwap(GameMessageSet* other) {
  game_message_.InternalSwap(&other->game_message_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GameMessageSet::GetMetadata() const {
  protobuf_GameMessage_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GameMessage_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GameMessageSet

// repeated .GameMessage game_message = 1;
int GameMessageSet::game_message_size() const {
  return game_message_.size();
}
void GameMessageSet::clear_game_message() {
  game_message_.Clear();
}
const ::GameMessage& GameMessageSet::game_message(int index) const {
  // @@protoc_insertion_point(field_get:GameMessageSet.game_message)
  return game_message_.Get(index);
}
::GameMessage* GameMessageSet::mutable_game_message(int index) {
  // @@protoc_insertion_point(field_mutable:GameMessageSet.game_message)
  return game_message_.Mutable(index);
}
::GameMessage* GameMessageSet::add_game_message() {
  // @@protoc_insertion_point(field_add:GameMessageSet.game_message)
  return game_message_.Add();
}
::google::protobuf::RepeatedPtrField< ::GameMessage >*
GameMessageSet::mutable_game_message() {
  // @@protoc_insertion_point(field_mutable_list:GameMessageSet.game_message)
  return &game_message_;
}
const ::google::protobuf::RepeatedPtrField< ::GameMessage >&
GameMessageSet::game_message() const {
  // @@protoc_insertion_point(field_list:GameMessageSet.game_message)
  return game_message_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)