// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_player.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "msg_player.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace PROTOBUF {

namespace {

const ::google::protobuf::Descriptor* PB_Player_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PB_Player_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* PB_TRoleState_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_msg_5fplayer_2eproto() {
  protobuf_AddDesc_msg_5fplayer_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "msg_player.proto");
  GOOGLE_CHECK(file != NULL);
  PB_Player_descriptor_ = file->message_type(0);
  static const int PB_Player_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PB_Player, role_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PB_Player, head_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PB_Player, nick_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PB_Player, last_host_),
  };
  PB_Player_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PB_Player_descriptor_,
      PB_Player::default_instance_,
      PB_Player_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PB_Player, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PB_Player, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PB_Player));
  PB_TRoleState_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_msg_5fplayer_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PB_Player_descriptor_, &PB_Player::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_msg_5fplayer_2eproto() {
  delete PB_Player::default_instance_;
  delete PB_Player_reflection_;
}

void protobuf_AddDesc_msg_5fplayer_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020msg_player.proto\022\010PROTOBUF\"S\n\tPB_Playe"
    "r\022\017\n\007role_id\030\001 \001(\r\022\017\n\007head_id\030\002 \001(\r\022\021\n\tn"
    "ick_name\030\003 \001(\t\022\021\n\tlast_host\030\004 \001(\t*$\n\rPB_"
    "TRoleState\022\023\n\017ROLE_STATE_NULL\020\000", 151);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "msg_player.proto", &protobuf_RegisterTypes);
  PB_Player::default_instance_ = new PB_Player();
  PB_Player::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_msg_5fplayer_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_msg_5fplayer_2eproto {
  StaticDescriptorInitializer_msg_5fplayer_2eproto() {
    protobuf_AddDesc_msg_5fplayer_2eproto();
  }
} static_descriptor_initializer_msg_5fplayer_2eproto_;
const ::google::protobuf::EnumDescriptor* PB_TRoleState_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PB_TRoleState_descriptor_;
}
bool PB_TRoleState_IsValid(int value) {
  switch(value) {
    case 0:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int PB_Player::kRoleIdFieldNumber;
const int PB_Player::kHeadIdFieldNumber;
const int PB_Player::kNickNameFieldNumber;
const int PB_Player::kLastHostFieldNumber;
#endif  // !_MSC_VER

PB_Player::PB_Player()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:PROTOBUF.PB_Player)
}

void PB_Player::InitAsDefaultInstance() {
}

PB_Player::PB_Player(const PB_Player& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:PROTOBUF.PB_Player)
}

void PB_Player::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  role_id_ = 0u;
  head_id_ = 0u;
  nick_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  last_host_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PB_Player::~PB_Player() {
  // @@protoc_insertion_point(destructor:PROTOBUF.PB_Player)
  SharedDtor();
}

void PB_Player::SharedDtor() {
  if (nick_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete nick_name_;
  }
  if (last_host_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete last_host_;
  }
  if (this != default_instance_) {
  }
}

void PB_Player::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PB_Player::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PB_Player_descriptor_;
}

const PB_Player& PB_Player::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_msg_5fplayer_2eproto();
  return *default_instance_;
}

PB_Player* PB_Player::default_instance_ = NULL;

PB_Player* PB_Player::New() const {
  return new PB_Player;
}

void PB_Player::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<PB_Player*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(role_id_, head_id_);
    if (has_nick_name()) {
      if (nick_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        nick_name_->clear();
      }
    }
    if (has_last_host()) {
      if (last_host_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        last_host_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PB_Player::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PROTOBUF.PB_Player)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 role_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &role_id_)));
          set_has_role_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_head_id;
        break;
      }

      // optional uint32 head_id = 2;
      case 2: {
        if (tag == 16) {
         parse_head_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &head_id_)));
          set_has_head_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_nick_name;
        break;
      }

      // optional string nick_name = 3;
      case 3: {
        if (tag == 26) {
         parse_nick_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nick_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->nick_name().data(), this->nick_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "nick_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_last_host;
        break;
      }

      // optional string last_host = 4;
      case 4: {
        if (tag == 34) {
         parse_last_host:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_last_host()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->last_host().data(), this->last_host().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "last_host");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PROTOBUF.PB_Player)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PROTOBUF.PB_Player)
  return false;
#undef DO_
}

void PB_Player::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PROTOBUF.PB_Player)
  // optional uint32 role_id = 1;
  if (has_role_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->role_id(), output);
  }

  // optional uint32 head_id = 2;
  if (has_head_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->head_id(), output);
  }

  // optional string nick_name = 3;
  if (has_nick_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nick_name().data(), this->nick_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nick_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->nick_name(), output);
  }

  // optional string last_host = 4;
  if (has_last_host()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->last_host().data(), this->last_host().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "last_host");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->last_host(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:PROTOBUF.PB_Player)
}

::google::protobuf::uint8* PB_Player::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:PROTOBUF.PB_Player)
  // optional uint32 role_id = 1;
  if (has_role_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->role_id(), target);
  }

  // optional uint32 head_id = 2;
  if (has_head_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->head_id(), target);
  }

  // optional string nick_name = 3;
  if (has_nick_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nick_name().data(), this->nick_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nick_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->nick_name(), target);
  }

  // optional string last_host = 4;
  if (has_last_host()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->last_host().data(), this->last_host().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "last_host");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->last_host(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PROTOBUF.PB_Player)
  return target;
}

int PB_Player::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 role_id = 1;
    if (has_role_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->role_id());
    }

    // optional uint32 head_id = 2;
    if (has_head_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->head_id());
    }

    // optional string nick_name = 3;
    if (has_nick_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->nick_name());
    }

    // optional string last_host = 4;
    if (has_last_host()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->last_host());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PB_Player::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PB_Player* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PB_Player*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PB_Player::MergeFrom(const PB_Player& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_role_id()) {
      set_role_id(from.role_id());
    }
    if (from.has_head_id()) {
      set_head_id(from.head_id());
    }
    if (from.has_nick_name()) {
      set_nick_name(from.nick_name());
    }
    if (from.has_last_host()) {
      set_last_host(from.last_host());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PB_Player::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PB_Player::CopyFrom(const PB_Player& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PB_Player::IsInitialized() const {

  return true;
}

void PB_Player::Swap(PB_Player* other) {
  if (other != this) {
    std::swap(role_id_, other->role_id_);
    std::swap(head_id_, other->head_id_);
    std::swap(nick_name_, other->nick_name_);
    std::swap(last_host_, other->last_host_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PB_Player::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PB_Player_descriptor_;
  metadata.reflection = PB_Player_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace PROTOBUF

// @@protoc_insertion_point(global_scope)
