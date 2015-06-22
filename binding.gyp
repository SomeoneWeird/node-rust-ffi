{
  "targets": [
    {
      "target_name": "nativeaddon",
      "sources": [ "nativeaddon.cc" ],
      "include_dirs": [ 
        "<!(node -e \"require('nan')\")"
      ],
      "libraries": [
        "../rust/library.dylib"
      ],
      "copies": [
        {
          "files": [ "rust/library.dylib" ],
          "destination": "."
        }
      ]
    }
  ]
}
