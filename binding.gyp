{
  "targets": [
    {
      "target_name": "nativeaddon",
      "sources": [ "nativeaddon.cc" ],
      "include_dirs": [ 
        "<!(node -e \"require('nan')\")",
        "rust",
        "../rust"
      ],
      "libraries": [
      ]
    }
  ]
}
