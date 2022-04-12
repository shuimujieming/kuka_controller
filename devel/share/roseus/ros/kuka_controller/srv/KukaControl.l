;; Auto-generated. Do not edit!


(when (boundp 'kuka_controller::KukaControl)
  (if (not (find-package "KUKA_CONTROLLER"))
    (make-package "KUKA_CONTROLLER"))
  (shadow 'KukaControl (find-package "KUKA_CONTROLLER")))
(unless (find-package "KUKA_CONTROLLER::KUKACONTROL")
  (make-package "KUKA_CONTROLLER::KUKACONTROL"))
(unless (find-package "KUKA_CONTROLLER::KUKACONTROLREQUEST")
  (make-package "KUKA_CONTROLLER::KUKACONTROLREQUEST"))
(unless (find-package "KUKA_CONTROLLER::KUKACONTROLRESPONSE")
  (make-package "KUKA_CONTROLLER::KUKACONTROLRESPONSE"))

(in-package "ROS")





(defclass kuka_controller::KukaControlRequest
  :super ros::object
  :slots (_x _y _z _a _b _c ))

(defmethod kuka_controller::KukaControlRequest
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:a __a) 0.0)
    ((:b __b) 0.0)
    ((:c __c) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _a (float __a))
   (setq _b (float __b))
   (setq _c (float __c))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:c
   (&optional __c)
   (if __c (setq _c __c)) _c)
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _z
    4
    ;; float32 _a
    4
    ;; float32 _b
    4
    ;; float32 _c
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _z
       (sys::poke _z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a
       (sys::poke _a (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _b
       (sys::poke _b (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _c
       (sys::poke _c (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _z
     (setq _z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a
     (setq _a (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _b
     (setq _b (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _c
     (setq _c (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass kuka_controller::KukaControlResponse
  :super ros::object
  :slots (_ret ))

(defmethod kuka_controller::KukaControlResponse
  (:init
   (&key
    ((:ret __ret) 0)
    )
   (send-super :init)
   (setq _ret (round __ret))
   self)
  (:ret
   (&optional __ret)
   (if __ret (setq _ret __ret)) _ret)
  (:serialization-length
   ()
   (+
    ;; int8 _ret
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _ret
       (write-byte _ret s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _ret
     (setq _ret (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _ret 127) (setq _ret (- _ret 256)))
   ;;
   self)
  )

(defclass kuka_controller::KukaControl
  :super ros::object
  :slots ())

(setf (get kuka_controller::KukaControl :md5sum-) "ed9dd79fb8a5d0474ef3928715b2e454")
(setf (get kuka_controller::KukaControl :datatype-) "kuka_controller/KukaControl")
(setf (get kuka_controller::KukaControl :request) kuka_controller::KukaControlRequest)
(setf (get kuka_controller::KukaControl :response) kuka_controller::KukaControlResponse)

(defmethod kuka_controller::KukaControlRequest
  (:response () (instance kuka_controller::KukaControlResponse :init)))

(setf (get kuka_controller::KukaControlRequest :md5sum-) "ed9dd79fb8a5d0474ef3928715b2e454")
(setf (get kuka_controller::KukaControlRequest :datatype-) "kuka_controller/KukaControlRequest")
(setf (get kuka_controller::KukaControlRequest :definition-)
      "float32 x
float32 y
float32 z
float32 a
float32 b
float32 c
---
int8 ret

")

(setf (get kuka_controller::KukaControlResponse :md5sum-) "ed9dd79fb8a5d0474ef3928715b2e454")
(setf (get kuka_controller::KukaControlResponse :datatype-) "kuka_controller/KukaControlResponse")
(setf (get kuka_controller::KukaControlResponse :definition-)
      "float32 x
float32 y
float32 z
float32 a
float32 b
float32 c
---
int8 ret

")



(provide :kuka_controller/KukaControl "ed9dd79fb8a5d0474ef3928715b2e454")


