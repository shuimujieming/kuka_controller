;; Auto-generated. Do not edit!


(when (boundp 'kuka_controller::ForceData)
  (if (not (find-package "KUKA_CONTROLLER"))
    (make-package "KUKA_CONTROLLER"))
  (shadow 'ForceData (find-package "KUKA_CONTROLLER")))
(unless (find-package "KUKA_CONTROLLER::FORCEDATA")
  (make-package "KUKA_CONTROLLER::FORCEDATA"))

(in-package "ROS")
;;//! \htmlinclude ForceData.msg.html


(defclass kuka_controller::ForceData
  :super ros::object
  :slots (_x _y _z _Mx _My _Mz ))

(defmethod kuka_controller::ForceData
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:Mx __Mx) 0.0)
    ((:My __My) 0.0)
    ((:Mz __Mz) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _Mx (float __Mx))
   (setq _My (float __My))
   (setq _Mz (float __Mz))
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
  (:Mx
   (&optional __Mx)
   (if __Mx (setq _Mx __Mx)) _Mx)
  (:My
   (&optional __My)
   (if __My (setq _My __My)) _My)
  (:Mz
   (&optional __Mz)
   (if __Mz (setq _Mz __Mz)) _Mz)
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _z
    4
    ;; float32 _Mx
    4
    ;; float32 _My
    4
    ;; float32 _Mz
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
     ;; float32 _Mx
       (sys::poke _Mx (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _My
       (sys::poke _My (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Mz
       (sys::poke _Mz (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
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
   ;; float32 _Mx
     (setq _Mx (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _My
     (setq _My (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Mz
     (setq _Mz (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get kuka_controller::ForceData :md5sum-) "c115518ba289f3faa6ed19329fa3a279")
(setf (get kuka_controller::ForceData :datatype-) "kuka_controller/ForceData")
(setf (get kuka_controller::ForceData :definition-)
      "float32 x
float32 y
float32 z
float32 Mx
float32 My
float32 Mz

")



(provide :kuka_controller/ForceData "c115518ba289f3faa6ed19329fa3a279")


