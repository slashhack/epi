#!/usr/bin/env bash

echo "This file is only used for developing purpose"

SCRATCH_DIR=scratch

rm -rf $SCRATCH_DIR
mkdir $SCRATCH_DIR
cd $SCRATCH_DIR && ../configure && make distcheck

