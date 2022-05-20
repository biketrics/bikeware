file(GLOB_RECURSE SOURCES ./*.cpp ./*.h)
idf_component_register(SRCS ${SOURCES}
                    REQUIRES driver
                    INCLUDE_DIRS . ../include)
