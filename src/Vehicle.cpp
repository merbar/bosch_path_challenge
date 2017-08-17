/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehicle.cpp
 * Author: merbar
 * 
 * Created on July 23, 2017, 1:34 PM
 */

#include "Vehicle.h"

Vehicle::Vehicle() {
  _pos_s = 0.0;
  _vel_s = 0.0;
  _acc_s = 0.0;
  _pos_d = 0.0;
  _vel_d = 0.0;
  _acc_d = 0.0;
}

Vehicle::Vehicle(const Vehicle& orig) {
}

Vehicle::~Vehicle() {
}

void Vehicle::set_frenet_pos(double pos_s, double pos_d) {
  _pos_s = pos_s;
  _pos_d = pos_d;
}

void Vehicle::set_frenet_motion(double vel_s, double acc_s, double vel_d, double acc_d) {
  _vel_s = vel_s;
  _acc_s = acc_s;
  _vel_d = vel_d;
  _acc_d = acc_d;
}

vector<double> Vehicle::get_s() const {
  return {_pos_s, _vel_s, _acc_s};
}

vector<double> Vehicle::get_d() const {
  return {_pos_d, _vel_d, _acc_d};
}

// returns frenet coordinates of predicted position at time t
// simplified assumption in line with project constraints
// - vehicle stays in lane
// - vehicle has constant speed
vector<double> Vehicle::state_at(double t) const {
  double new_s = _pos_s + t * _vel_s;
  return {new_s, _pos_d};
}