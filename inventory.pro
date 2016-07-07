TEMPLATE = subdirs

CONFIG+=ordered

SUBDIRS += \
    invModel \
    invController \
    invApp \    
    invModelTest \
    invControllerTest


invModelTest.depends = invModel
invControllerTest.depends = invModel
invControllerTest.depends = invController
	
OTHER_FILES += \
    defaults.pri

