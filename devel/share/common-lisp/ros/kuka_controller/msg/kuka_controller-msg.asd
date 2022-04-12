
(cl:in-package :asdf)

(defsystem "kuka_controller-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ForceData" :depends-on ("_package_ForceData"))
    (:file "_package_ForceData" :depends-on ("_package"))
    (:file "PositionData" :depends-on ("_package_PositionData"))
    (:file "_package_PositionData" :depends-on ("_package"))
  ))