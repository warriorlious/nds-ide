# This file was automatically generated by SWIG (http://www.swig.org).
# Version 1.3.31
#
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _ipc
import new
new_instancemethod = new.instancemethod
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


tpl_ipc_create_instance = _ipc.tpl_ipc_create_instance
tpl_sem_post_fifo_full_sem = _ipc.tpl_sem_post_fifo_full_sem
tpl_ipc_destroy_instance = _ipc.tpl_ipc_destroy_instance
tpl_ipc_send_it = _ipc.tpl_ipc_send_it
tpl_ipc_get_pid = _ipc.tpl_ipc_get_pid
tpl_ipc_write_reg = _ipc.tpl_ipc_write_reg
tpl_ipc_read_reg = _ipc.tpl_ipc_read_reg
tpl_ipc_ready = _ipc.tpl_ipc_ready
tpl_ipc_wait_tpl = _ipc.tpl_ipc_wait_tpl
tpl_ipc_pop_fifo = _ipc.tpl_ipc_pop_fifo
tpl_ipc_create_global_memory = _ipc.tpl_ipc_create_global_memory
tpl_ipc_destroy_global_memory = _ipc.tpl_ipc_destroy_global_memory
write_global_time = _ipc.write_global_time
FIFO_SIZE = _ipc.FIFO_SIZE
REGISTERS_NB = _ipc.REGISTERS_NB
FILE_PATH_LEN = _ipc.FILE_PATH_LEN
REGISTER_ID_BITS = _ipc.REGISTER_ID_BITS
DEVICE_MASK = _ipc.DEVICE_MASK
REGISTER_MASK = _ipc.REGISTER_MASK
REGISTER_MAX = _ipc.REGISTER_MAX
DATA_FILE_PATH = _ipc.DATA_FILE_PATH
GLOBAL_DATA_FILE_PATH = _ipc.GLOBAL_DATA_FILE_PATH
VP_SEM_FILE_PATH = _ipc.VP_SEM_FILE_PATH
TPL_SEM_FILE_PATH = _ipc.TPL_SEM_FILE_PATH
IT_ID_SEM_FILE_PATH = _ipc.IT_ID_SEM_FILE_PATH
FIFO_FULL_SEM_FILE_PATH = _ipc.FIFO_FULL_SEM_FILE_PATH
FIFO_EMPTY_SEM_FILE_PATH = _ipc.FIFO_EMPTY_SEM_FILE_PATH
GLOBAL_SEM_FILE_PATH = _ipc.GLOBAL_SEM_FILE_PATH
REG_SEM_FILE_PATH = _ipc.REG_SEM_FILE_PATH
class modified_reg_t(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, modified_reg_t, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, modified_reg_t, name)
    __repr__ = _swig_repr
    __swig_setmethods__["dev"] = _ipc.modified_reg_t_dev_set
    __swig_getmethods__["dev"] = _ipc.modified_reg_t_dev_get
    if _newclass:dev = _swig_property(_ipc.modified_reg_t_dev_get, _ipc.modified_reg_t_dev_set)
    __swig_setmethods__["reg_mask"] = _ipc.modified_reg_t_reg_mask_set
    __swig_getmethods__["reg_mask"] = _ipc.modified_reg_t_reg_mask_get
    if _newclass:reg_mask = _swig_property(_ipc.modified_reg_t_reg_mask_get, _ipc.modified_reg_t_reg_mask_set)
    __swig_setmethods__["time"] = _ipc.modified_reg_t_time_set
    __swig_getmethods__["time"] = _ipc.modified_reg_t_time_get
    if _newclass:time = _swig_property(_ipc.modified_reg_t_time_get, _ipc.modified_reg_t_time_set)
    def __init__(self, *args): 
        this = _ipc.new_modified_reg_t(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _ipc.delete_modified_reg_t
    __del__ = lambda self : None;
modified_reg_t_swigregister = _ipc.modified_reg_t_swigregister
modified_reg_t_swigregister(modified_reg_t)


