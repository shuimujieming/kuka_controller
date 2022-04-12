; Auto-generated. Do not edit!


(cl:in-package kuka_controller-srv)


;//! \htmlinclude KukaControl-request.msg.html

(cl:defclass <KukaControl-request> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0)
   (a
    :reader a
    :initarg :a
    :type cl:float
    :initform 0.0)
   (b
    :reader b
    :initarg :b
    :type cl:float
    :initform 0.0)
   (c
    :reader c
    :initarg :c
    :type cl:float
    :initform 0.0))
)

(cl:defclass KukaControl-request (<KukaControl-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KukaControl-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KukaControl-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kuka_controller-srv:<KukaControl-request> is deprecated: use kuka_controller-srv:KukaControl-request instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <KukaControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-srv:x-val is deprecated.  Use kuka_controller-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <KukaControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-srv:y-val is deprecated.  Use kuka_controller-srv:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <KukaControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-srv:z-val is deprecated.  Use kuka_controller-srv:z instead.")
  (z m))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <KukaControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-srv:a-val is deprecated.  Use kuka_controller-srv:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <KukaControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-srv:b-val is deprecated.  Use kuka_controller-srv:b instead.")
  (b m))

(cl:ensure-generic-function 'c-val :lambda-list '(m))
(cl:defmethod c-val ((m <KukaControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-srv:c-val is deprecated.  Use kuka_controller-srv:c instead.")
  (c m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KukaControl-request>) ostream)
  "Serializes a message object of type '<KukaControl-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'b))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'c))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KukaControl-request>) istream)
  "Deserializes a message object of type '<KukaControl-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'b) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'c) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KukaControl-request>)))
  "Returns string type for a service object of type '<KukaControl-request>"
  "kuka_controller/KukaControlRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KukaControl-request)))
  "Returns string type for a service object of type 'KukaControl-request"
  "kuka_controller/KukaControlRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KukaControl-request>)))
  "Returns md5sum for a message object of type '<KukaControl-request>"
  "ed9dd79fb8a5d0474ef3928715b2e454")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KukaControl-request)))
  "Returns md5sum for a message object of type 'KukaControl-request"
  "ed9dd79fb8a5d0474ef3928715b2e454")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KukaControl-request>)))
  "Returns full string definition for message of type '<KukaControl-request>"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%float32 a~%float32 b~%float32 c~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KukaControl-request)))
  "Returns full string definition for message of type 'KukaControl-request"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%float32 a~%float32 b~%float32 c~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KukaControl-request>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KukaControl-request>))
  "Converts a ROS message object to a list"
  (cl:list 'KukaControl-request
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
    (cl:cons ':c (c msg))
))
;//! \htmlinclude KukaControl-response.msg.html

(cl:defclass <KukaControl-response> (roslisp-msg-protocol:ros-message)
  ((ret
    :reader ret
    :initarg :ret
    :type cl:fixnum
    :initform 0))
)

(cl:defclass KukaControl-response (<KukaControl-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KukaControl-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KukaControl-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kuka_controller-srv:<KukaControl-response> is deprecated: use kuka_controller-srv:KukaControl-response instead.")))

(cl:ensure-generic-function 'ret-val :lambda-list '(m))
(cl:defmethod ret-val ((m <KukaControl-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-srv:ret-val is deprecated.  Use kuka_controller-srv:ret instead.")
  (ret m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KukaControl-response>) ostream)
  "Serializes a message object of type '<KukaControl-response>"
  (cl:let* ((signed (cl:slot-value msg 'ret)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KukaControl-response>) istream)
  "Deserializes a message object of type '<KukaControl-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ret) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KukaControl-response>)))
  "Returns string type for a service object of type '<KukaControl-response>"
  "kuka_controller/KukaControlResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KukaControl-response)))
  "Returns string type for a service object of type 'KukaControl-response"
  "kuka_controller/KukaControlResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KukaControl-response>)))
  "Returns md5sum for a message object of type '<KukaControl-response>"
  "ed9dd79fb8a5d0474ef3928715b2e454")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KukaControl-response)))
  "Returns md5sum for a message object of type 'KukaControl-response"
  "ed9dd79fb8a5d0474ef3928715b2e454")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KukaControl-response>)))
  "Returns full string definition for message of type '<KukaControl-response>"
  (cl:format cl:nil "int8 ret~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KukaControl-response)))
  "Returns full string definition for message of type 'KukaControl-response"
  (cl:format cl:nil "int8 ret~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KukaControl-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KukaControl-response>))
  "Converts a ROS message object to a list"
  (cl:list 'KukaControl-response
    (cl:cons ':ret (ret msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'KukaControl)))
  'KukaControl-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'KukaControl)))
  'KukaControl-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KukaControl)))
  "Returns string type for a service object of type '<KukaControl>"
  "kuka_controller/KukaControl")