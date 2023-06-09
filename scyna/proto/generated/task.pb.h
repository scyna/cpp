// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: task.proto

#ifndef PROTOBUF_INCLUDED_task_2eproto
#define PROTOBUF_INCLUDED_task_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_task_2eproto 

namespace protobuf_task_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_task_2eproto
namespace scyna_proto {
class StartTaskRequest;
class StartTaskRequestDefaultTypeInternal;
extern StartTaskRequestDefaultTypeInternal _StartTaskRequest_default_instance_;
class StartTaskResponse;
class StartTaskResponseDefaultTypeInternal;
extern StartTaskResponseDefaultTypeInternal _StartTaskResponse_default_instance_;
class StopTaskRequest;
class StopTaskRequestDefaultTypeInternal;
extern StopTaskRequestDefaultTypeInternal _StopTaskRequest_default_instance_;
class Task;
class TaskDefaultTypeInternal;
extern TaskDefaultTypeInternal _Task_default_instance_;
}  // namespace scyna_proto
namespace google {
namespace protobuf {
template<> ::scyna_proto::StartTaskRequest* Arena::CreateMaybeMessage<::scyna_proto::StartTaskRequest>(Arena*);
template<> ::scyna_proto::StartTaskResponse* Arena::CreateMaybeMessage<::scyna_proto::StartTaskResponse>(Arena*);
template<> ::scyna_proto::StopTaskRequest* Arena::CreateMaybeMessage<::scyna_proto::StopTaskRequest>(Arena*);
template<> ::scyna_proto::Task* Arena::CreateMaybeMessage<::scyna_proto::Task>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace scyna_proto {

// ===================================================================

class StartTaskRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:scyna_proto.StartTaskRequest) */ {
 public:
  StartTaskRequest();
  virtual ~StartTaskRequest();

  StartTaskRequest(const StartTaskRequest& from);

  inline StartTaskRequest& operator=(const StartTaskRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StartTaskRequest(StartTaskRequest&& from) noexcept
    : StartTaskRequest() {
    *this = ::std::move(from);
  }

  inline StartTaskRequest& operator=(StartTaskRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const StartTaskRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StartTaskRequest* internal_default_instance() {
    return reinterpret_cast<const StartTaskRequest*>(
               &_StartTaskRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(StartTaskRequest* other);
  friend void swap(StartTaskRequest& a, StartTaskRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StartTaskRequest* New() const final {
    return CreateMaybeMessage<StartTaskRequest>(NULL);
  }

  StartTaskRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<StartTaskRequest>(arena);
  }
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StartTaskRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string Module = 1;
  void clear_module();
  static const int kModuleFieldNumber = 1;
  const ::std::string& module() const;
  void set_module(const ::std::string& value);
  #if LANG_CXX11
  void set_module(::std::string&& value);
  #endif
  void set_module(const char* value);
  void set_module(const char* value, size_t size);
  ::std::string* mutable_module();
  ::std::string* release_module();
  void set_allocated_module(::std::string* module);

  // string Topic = 2;
  void clear_topic();
  static const int kTopicFieldNumber = 2;
  const ::std::string& topic() const;
  void set_topic(const ::std::string& value);
  #if LANG_CXX11
  void set_topic(::std::string&& value);
  #endif
  void set_topic(const char* value);
  void set_topic(const char* value, size_t size);
  ::std::string* mutable_topic();
  ::std::string* release_topic();
  void set_allocated_topic(::std::string* topic);

  // bytes Data = 3;
  void clear_data();
  static const int kDataFieldNumber = 3;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // int64 Time = 4;
  void clear_time();
  static const int kTimeFieldNumber = 4;
  ::google::protobuf::int64 time() const;
  void set_time(::google::protobuf::int64 value);

  // int64 Interval = 5;
  void clear_interval();
  static const int kIntervalFieldNumber = 5;
  ::google::protobuf::int64 interval() const;
  void set_interval(::google::protobuf::int64 value);

  // uint64 Loop = 6;
  void clear_loop();
  static const int kLoopFieldNumber = 6;
  ::google::protobuf::uint64 loop() const;
  void set_loop(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:scyna_proto.StartTaskRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr module_;
  ::google::protobuf::internal::ArenaStringPtr topic_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  ::google::protobuf::int64 time_;
  ::google::protobuf::int64 interval_;
  ::google::protobuf::uint64 loop_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_task_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class StartTaskResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:scyna_proto.StartTaskResponse) */ {
 public:
  StartTaskResponse();
  virtual ~StartTaskResponse();

  StartTaskResponse(const StartTaskResponse& from);

  inline StartTaskResponse& operator=(const StartTaskResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StartTaskResponse(StartTaskResponse&& from) noexcept
    : StartTaskResponse() {
    *this = ::std::move(from);
  }

  inline StartTaskResponse& operator=(StartTaskResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const StartTaskResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StartTaskResponse* internal_default_instance() {
    return reinterpret_cast<const StartTaskResponse*>(
               &_StartTaskResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(StartTaskResponse* other);
  friend void swap(StartTaskResponse& a, StartTaskResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StartTaskResponse* New() const final {
    return CreateMaybeMessage<StartTaskResponse>(NULL);
  }

  StartTaskResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<StartTaskResponse>(arena);
  }
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StartTaskResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint64 Id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint64 id() const;
  void set_id(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:scyna_proto.StartTaskResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_task_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class StopTaskRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:scyna_proto.StopTaskRequest) */ {
 public:
  StopTaskRequest();
  virtual ~StopTaskRequest();

  StopTaskRequest(const StopTaskRequest& from);

  inline StopTaskRequest& operator=(const StopTaskRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StopTaskRequest(StopTaskRequest&& from) noexcept
    : StopTaskRequest() {
    *this = ::std::move(from);
  }

  inline StopTaskRequest& operator=(StopTaskRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const StopTaskRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StopTaskRequest* internal_default_instance() {
    return reinterpret_cast<const StopTaskRequest*>(
               &_StopTaskRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(StopTaskRequest* other);
  friend void swap(StopTaskRequest& a, StopTaskRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StopTaskRequest* New() const final {
    return CreateMaybeMessage<StopTaskRequest>(NULL);
  }

  StopTaskRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<StopTaskRequest>(arena);
  }
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StopTaskRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint64 Id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint64 id() const;
  void set_id(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:scyna_proto.StopTaskRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_task_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Task : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:scyna_proto.Task) */ {
 public:
  Task();
  virtual ~Task();

  Task(const Task& from);

  inline Task& operator=(const Task& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Task(Task&& from) noexcept
    : Task() {
    *this = ::std::move(from);
  }

  inline Task& operator=(Task&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Task& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Task* internal_default_instance() {
    return reinterpret_cast<const Task*>(
               &_Task_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(Task* other);
  friend void swap(Task& a, Task& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Task* New() const final {
    return CreateMaybeMessage<Task>(NULL);
  }

  Task* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Task>(arena);
  }
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Task* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes Data = 2;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // uint64 TraceID = 1;
  void clear_traceid();
  static const int kTraceIDFieldNumber = 1;
  ::google::protobuf::uint64 traceid() const;
  void set_traceid(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:scyna_proto.Task)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  ::google::protobuf::uint64 traceid_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_task_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// StartTaskRequest

// string Module = 1;
inline void StartTaskRequest::clear_module() {
  module_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& StartTaskRequest::module() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StartTaskRequest.Module)
  return module_.GetNoArena();
}
inline void StartTaskRequest::set_module(const ::std::string& value) {
  
  module_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:scyna_proto.StartTaskRequest.Module)
}
#if LANG_CXX11
inline void StartTaskRequest::set_module(::std::string&& value) {
  
  module_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:scyna_proto.StartTaskRequest.Module)
}
#endif
inline void StartTaskRequest::set_module(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  module_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:scyna_proto.StartTaskRequest.Module)
}
inline void StartTaskRequest::set_module(const char* value, size_t size) {
  
  module_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:scyna_proto.StartTaskRequest.Module)
}
inline ::std::string* StartTaskRequest::mutable_module() {
  
  // @@protoc_insertion_point(field_mutable:scyna_proto.StartTaskRequest.Module)
  return module_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StartTaskRequest::release_module() {
  // @@protoc_insertion_point(field_release:scyna_proto.StartTaskRequest.Module)
  
  return module_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StartTaskRequest::set_allocated_module(::std::string* module) {
  if (module != NULL) {
    
  } else {
    
  }
  module_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), module);
  // @@protoc_insertion_point(field_set_allocated:scyna_proto.StartTaskRequest.Module)
}

// string Topic = 2;
inline void StartTaskRequest::clear_topic() {
  topic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& StartTaskRequest::topic() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StartTaskRequest.Topic)
  return topic_.GetNoArena();
}
inline void StartTaskRequest::set_topic(const ::std::string& value) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:scyna_proto.StartTaskRequest.Topic)
}
#if LANG_CXX11
inline void StartTaskRequest::set_topic(::std::string&& value) {
  
  topic_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:scyna_proto.StartTaskRequest.Topic)
}
#endif
inline void StartTaskRequest::set_topic(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:scyna_proto.StartTaskRequest.Topic)
}
inline void StartTaskRequest::set_topic(const char* value, size_t size) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:scyna_proto.StartTaskRequest.Topic)
}
inline ::std::string* StartTaskRequest::mutable_topic() {
  
  // @@protoc_insertion_point(field_mutable:scyna_proto.StartTaskRequest.Topic)
  return topic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StartTaskRequest::release_topic() {
  // @@protoc_insertion_point(field_release:scyna_proto.StartTaskRequest.Topic)
  
  return topic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StartTaskRequest::set_allocated_topic(::std::string* topic) {
  if (topic != NULL) {
    
  } else {
    
  }
  topic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), topic);
  // @@protoc_insertion_point(field_set_allocated:scyna_proto.StartTaskRequest.Topic)
}

// bytes Data = 3;
inline void StartTaskRequest::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& StartTaskRequest::data() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StartTaskRequest.Data)
  return data_.GetNoArena();
}
inline void StartTaskRequest::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:scyna_proto.StartTaskRequest.Data)
}
#if LANG_CXX11
inline void StartTaskRequest::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:scyna_proto.StartTaskRequest.Data)
}
#endif
inline void StartTaskRequest::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:scyna_proto.StartTaskRequest.Data)
}
inline void StartTaskRequest::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:scyna_proto.StartTaskRequest.Data)
}
inline ::std::string* StartTaskRequest::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:scyna_proto.StartTaskRequest.Data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StartTaskRequest::release_data() {
  // @@protoc_insertion_point(field_release:scyna_proto.StartTaskRequest.Data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StartTaskRequest::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:scyna_proto.StartTaskRequest.Data)
}

// int64 Time = 4;
inline void StartTaskRequest::clear_time() {
  time_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 StartTaskRequest::time() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StartTaskRequest.Time)
  return time_;
}
inline void StartTaskRequest::set_time(::google::protobuf::int64 value) {
  
  time_ = value;
  // @@protoc_insertion_point(field_set:scyna_proto.StartTaskRequest.Time)
}

// int64 Interval = 5;
inline void StartTaskRequest::clear_interval() {
  interval_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 StartTaskRequest::interval() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StartTaskRequest.Interval)
  return interval_;
}
inline void StartTaskRequest::set_interval(::google::protobuf::int64 value) {
  
  interval_ = value;
  // @@protoc_insertion_point(field_set:scyna_proto.StartTaskRequest.Interval)
}

// uint64 Loop = 6;
inline void StartTaskRequest::clear_loop() {
  loop_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 StartTaskRequest::loop() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StartTaskRequest.Loop)
  return loop_;
}
inline void StartTaskRequest::set_loop(::google::protobuf::uint64 value) {
  
  loop_ = value;
  // @@protoc_insertion_point(field_set:scyna_proto.StartTaskRequest.Loop)
}

// -------------------------------------------------------------------

// StartTaskResponse

// uint64 Id = 1;
inline void StartTaskResponse::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 StartTaskResponse::id() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StartTaskResponse.Id)
  return id_;
}
inline void StartTaskResponse::set_id(::google::protobuf::uint64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:scyna_proto.StartTaskResponse.Id)
}

// -------------------------------------------------------------------

// StopTaskRequest

// uint64 Id = 1;
inline void StopTaskRequest::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 StopTaskRequest::id() const {
  // @@protoc_insertion_point(field_get:scyna_proto.StopTaskRequest.Id)
  return id_;
}
inline void StopTaskRequest::set_id(::google::protobuf::uint64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:scyna_proto.StopTaskRequest.Id)
}

// -------------------------------------------------------------------

// Task

// uint64 TraceID = 1;
inline void Task::clear_traceid() {
  traceid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Task::traceid() const {
  // @@protoc_insertion_point(field_get:scyna_proto.Task.TraceID)
  return traceid_;
}
inline void Task::set_traceid(::google::protobuf::uint64 value) {
  
  traceid_ = value;
  // @@protoc_insertion_point(field_set:scyna_proto.Task.TraceID)
}

// bytes Data = 2;
inline void Task::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Task::data() const {
  // @@protoc_insertion_point(field_get:scyna_proto.Task.Data)
  return data_.GetNoArena();
}
inline void Task::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:scyna_proto.Task.Data)
}
#if LANG_CXX11
inline void Task::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:scyna_proto.Task.Data)
}
#endif
inline void Task::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:scyna_proto.Task.Data)
}
inline void Task::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:scyna_proto.Task.Data)
}
inline ::std::string* Task::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:scyna_proto.Task.Data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Task::release_data() {
  // @@protoc_insertion_point(field_release:scyna_proto.Task.Data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Task::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:scyna_proto.Task.Data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace scyna_proto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_task_2eproto
