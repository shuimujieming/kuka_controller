// Auto-generated. Do not edit!

// (in-package kuka_controller.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ForceData {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x = null;
      this.y = null;
      this.z = null;
      this.Mx = null;
      this.My = null;
      this.Mz = null;
    }
    else {
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('Mx')) {
        this.Mx = initObj.Mx
      }
      else {
        this.Mx = 0.0;
      }
      if (initObj.hasOwnProperty('My')) {
        this.My = initObj.My
      }
      else {
        this.My = 0.0;
      }
      if (initObj.hasOwnProperty('Mz')) {
        this.Mz = initObj.Mz
      }
      else {
        this.Mz = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ForceData
    // Serialize message field [x]
    bufferOffset = _serializer.float32(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float32(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float32(obj.z, buffer, bufferOffset);
    // Serialize message field [Mx]
    bufferOffset = _serializer.float32(obj.Mx, buffer, bufferOffset);
    // Serialize message field [My]
    bufferOffset = _serializer.float32(obj.My, buffer, bufferOffset);
    // Serialize message field [Mz]
    bufferOffset = _serializer.float32(obj.Mz, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ForceData
    let len;
    let data = new ForceData(null);
    // Deserialize message field [x]
    data.x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Mx]
    data.Mx = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [My]
    data.My = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Mz]
    data.Mz = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kuka_controller/ForceData';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c115518ba289f3faa6ed19329fa3a279';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 x
    float32 y
    float32 z
    float32 Mx
    float32 My
    float32 Mz
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ForceData(null);
    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.Mx !== undefined) {
      resolved.Mx = msg.Mx;
    }
    else {
      resolved.Mx = 0.0
    }

    if (msg.My !== undefined) {
      resolved.My = msg.My;
    }
    else {
      resolved.My = 0.0
    }

    if (msg.Mz !== undefined) {
      resolved.Mz = msg.Mz;
    }
    else {
      resolved.Mz = 0.0
    }

    return resolved;
    }
};

module.exports = ForceData;
