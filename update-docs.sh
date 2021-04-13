#!/bin/sh
MN_DEF_MAIN_PATH="docs-git/docs"
MN_DEF_VERSION=0
MN_DEF_BASE_DIR="$( cd "$( dirname "$0" )" && pwd )"

function parse_json() {
	JSONDATA=$(cat library.json)
	MN_DEF_VERSION=$(echo "$JSONDATA"|grep -w \"version\" |tail -1 | cut -d\" -f4)
}
function create_and_push_doxy() {
	doxygen

	cd "$MN_DEF_BASE_DIR/doc/$MN_DEF_MAIN_PATH"
	git commit -a -m "update to version ${MN_DEF_VERSION}"
	git push
}

function main() {
    parse_json
    create_and_push_doxy "$@"
}

main "$@"
