//
// Created by ta3ik on 25.09.2020.
//

#include "MyDLL.h"

LinkedList::iterator::iterator() {

}

LinkedList::iterator &LinkedList::iterator::operator=(const LinkedList::iterator &other) {

}


bool LinkedList::iterator::operator!=(const iterator &other) const {

}

bool LinkedList::iterator::operator==(const LinkedList::iterator &other) const {

}

value_type &LinkedList::iterator::operator*() {

}

value_type *LinkedList::iterator::operator->() {

}

LinkedList::iterator &LinkedList::iterator::operator++() {

}

LinkedList::iterator LinkedList::iterator::operator++(int) {

}

LinkedList::iterator &LinkedList::iterator::operator--() {

}

LinkedList::iterator LinkedList::iterator::operator--(int) {

}

LinkedList::const_iterator::const_iterator() {

}

LinkedList::const_iterator &LinkedList::const_iterator::operator=(const LinkedList::const_iterator &other) {

}

bool LinkedList::const_iterator::operator!=(const LinkedList::const_iterator &other) const {

}

bool LinkedList::const_iterator::operator==(const LinkedList::const_iterator &other) const {

}

const value_type &LinkedList::const_iterator::operator*() const {

}

const value_type *LinkedList::const_iterator::operator->() const {

}

LinkedList::const_iterator &LinkedList::const_iterator::operator++() {

}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int) {

}

LinkedList::const_iterator &LinkedList::const_iterator::operator--() {

}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int) {

}

LinkedList::LinkedList() {

}

LinkedList::LinkedList(const LinkedList &other) {

}

LinkedList::LinkedList(LinkedList &&other) {

}

LinkedList::~LinkedList() {

}

LinkedList &LinkedList::operator=(const LinkedList &other) {

}

LinkedList &LinkedList::operator=(LinkedList &&other) {

}

LinkedList::iterator LinkedList::begin() {

}

LinkedList::const_iterator LinkedList::begin() const {

}

LinkedList::const_iterator LinkedList::cbegin() const {

}

LinkedList::iterator LinkedList::end() {

}

LinkedList::const_iterator LinkedList::end() const {

}

LinkedList::const_iterator LinkedList::cend() const {

}

int LinkedList::size() const {

}

bool LinkedList::empty() const {

}

value_type &LinkedList::front() {

}

const value_type &LinkedList::front() const {

}

value_type &LinkedList::back() {

}

const value_type &LinkedList::back() const {

}

LinkedList::iterator LinkedList::erase(LinkedList::iterator position) {

}

LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {

}

int LinkedList::remove(const value_type &value) {

}

void LinkedList::clear() {

}

void LinkedList::pop_back() {

}

void LinkedList::pop_front() {

}

void LinkedList::push_back(const value_type &value) {

}

void LinkedList::push_front(const value_type &value) {

}

LinkedList::iterator LinkedList::insert(LinkedList::iterator before, const value_type &value) {

}

LinkedList &LinkedList::operator+=(const LinkedList &other) {

}

bool operator!=(const LinkedList &left, const LinkedList &right) {

}

bool operator==(const LinkedList &left, const LinkedList &right) {

}
