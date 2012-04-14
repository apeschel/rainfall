#!/usr/bin/env python2
# encoding: utf-8

APPNAME = 'rainfall'
VERSION = '1.0'

top = '.'
out = 'build'

def options(opt):
    opt.load('compiler_cxx')

def configure(conf):
    conf.load('compiler_cxx')
    conf.env['CXXFLAGS'] = ['-Wall', '--std=c++0x']
    conf.check(
            features='cxx cxxprogram',
            lib=['stdc++'],
            uselib_store='stdc++')

def build(bld):
    bld.recurse('src')
