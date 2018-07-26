TEMPLATE = subdirs
SUBDIRS = libnodes \
          StoryWriter

libnodes.subdir = libnodes

StoryWriter.subdir = StoryWriter
StoryWriter.depends = libnodes


# build must be last:
