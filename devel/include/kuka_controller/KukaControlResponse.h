// Generated by gencpp from file kuka_controller/KukaControlResponse.msg
// DO NOT EDIT!


#ifndef KUKA_CONTROLLER_MESSAGE_KUKACONTROLRESPONSE_H
#define KUKA_CONTROLLER_MESSAGE_KUKACONTROLRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace kuka_controller
{
template <class ContainerAllocator>
struct KukaControlResponse_
{
  typedef KukaControlResponse_<ContainerAllocator> Type;

  KukaControlResponse_()
    : ret(0)  {
    }
  KukaControlResponse_(const ContainerAllocator& _alloc)
    : ret(0)  {
  (void)_alloc;
    }



   typedef int8_t _ret_type;
  _ret_type ret;





  typedef boost::shared_ptr< ::kuka_controller::KukaControlResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kuka_controller::KukaControlResponse_<ContainerAllocator> const> ConstPtr;

}; // struct KukaControlResponse_

typedef ::kuka_controller::KukaControlResponse_<std::allocator<void> > KukaControlResponse;

typedef boost::shared_ptr< ::kuka_controller::KukaControlResponse > KukaControlResponsePtr;
typedef boost::shared_ptr< ::kuka_controller::KukaControlResponse const> KukaControlResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kuka_controller::KukaControlResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::kuka_controller::KukaControlResponse_<ContainerAllocator1> & lhs, const ::kuka_controller::KukaControlResponse_<ContainerAllocator2> & rhs)
{
  return lhs.ret == rhs.ret;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::kuka_controller::KukaControlResponse_<ContainerAllocator1> & lhs, const ::kuka_controller::KukaControlResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace kuka_controller

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kuka_controller::KukaControlResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kuka_controller::KukaControlResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kuka_controller::KukaControlResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ba0ef05866f4fc5d7e82544d27e5cfbc";
  }

  static const char* value(const ::kuka_controller::KukaControlResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xba0ef05866f4fc5dULL;
  static const uint64_t static_value2 = 0x7e82544d27e5cfbcULL;
};

template<class ContainerAllocator>
struct DataType< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kuka_controller/KukaControlResponse";
  }

  static const char* value(const ::kuka_controller::KukaControlResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 ret\n"
"\n"
;
  }

  static const char* value(const ::kuka_controller::KukaControlResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ret);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct KukaControlResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kuka_controller::KukaControlResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kuka_controller::KukaControlResponse_<ContainerAllocator>& v)
  {
    s << indent << "ret: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ret);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KUKA_CONTROLLER_MESSAGE_KUKACONTROLRESPONSE_H
