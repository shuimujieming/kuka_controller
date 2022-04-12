; Auto-generated. Do not edit!


(cl:in-package kuka_controller-msg)


;//! \htmlinclude ForceData.msg.html

(cl:defclass <ForceData> (roslisp-msg-protocol:ros-message)
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
   (Mx
    :reader Mx
    :initarg :Mx
    :type cl:float
    :initform 0.0)
   (My
    :reader My
    :initarg :My
    :type cl:float
    :initform 0.0)
   (Mz
    :reader Mz
    :initarg :Mz
    :type cl:float
    :initform 0.0))
)

(cl:defclass ForceData (<ForceData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ForceData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ForceData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kuka_controller-msg:<ForceData> is deprecated: use kuka_controller-msg:ForceData instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <ForceData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-msg:x-val is deprecated.  Use kuka_controller-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <ForceData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-msg:y-val is deprecated.  Use kuka_controller-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <ForceData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-msg:z-val is deprecated.  Use kuka_controller-msg:z instead.")
  (z m))

(cl:ensure-generic-function 'Mx-val :lambda-list '(m))
(cl:defmethod Mx-val ((m <ForceData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-msg:Mx-val is deprecated.  Use kuka_controller-msg:Mx instead.")
  (Mx m))

(cl:ensure-generic-function 'My-val :lambda-list '(m))
(cl:defmethod My-val ((m <ForceData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-msg:My-val is deprecated.  Use kuka_controller-msg:My instead.")
  (My m))

(cl:ensure-generic-function 'Mz-val :lambda-list '(m))
(cl:defmethod Mz-val ((m <ForceData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kuka_controller-msg:Mz-val is deprecated.  Use kuka_controller-msg:Mz instead.")
  (Mz m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ForceData>) ostream)
  "Serializes a message object of type '<ForceData>"
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Mx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'My))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Mz))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ForceData>) istream)
  "Deserializes a message object of type '<ForceData>"
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
    (cl:setf (cl:slot-value msg 'Mx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'My) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Mz) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ForceData>)))
  "Returns string type for a message object of type '<ForceData>"
  "kuka_controller/ForceData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ForceData)))
  "Returns string type for a message object of type 'ForceData"
  "kuka_controller/ForceData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ForceData>)))
  "Returns md5sum for a message object of type '<ForceData>"
  "c115518ba289f3faa6ed19329fa3a279")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ForceData)))
  "Returns md5sum for a message object of type 'ForceData"
  "c115518ba289f3faa6ed19329fa3a279")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ForceData>)))
  "Returns full string definition for message of type '<ForceData>"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%float32 Mx~%float32 My~%float32 Mz~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ForceData)))
  "Returns full string definition for message of type 'ForceData"
  (cl:format cl:nil "float32 x~%float32 y~%float32 z~%float32 Mx~%float32 My~%float32 Mz~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ForceData>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ForceData>))
  "Converts a ROS message object to a list"
  (cl:list 'ForceData
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
    (cl:cons ':Mx (Mx msg))
    (cl:cons ':My (My msg))
    (cl:cons ':Mz (Mz msg))
))
