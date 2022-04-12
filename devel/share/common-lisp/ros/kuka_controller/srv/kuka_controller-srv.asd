
(cl:in-package :asdf)

(defsystem "kuka_controller-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "KukaControl" :depends-on ("_package_KukaControl"))
    (:file "_package_KukaControl" :depends-on ("_package"))
  ))